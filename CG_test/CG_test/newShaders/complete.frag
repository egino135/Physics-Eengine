#version 330 core

#define NR_POINT_LIGHTS 2 

out vec4 color;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

struct Material
{
    sampler2D texture_diffuse;
    sampler2D texture_specular;
	sampler2D emission;	
	vec3 diffuse;
	vec3 ambient;
	vec3 specular;
    float shininess;
};
struct SpotLight
{
	vec3 position;
	vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
	float constant;
	float linear;
	float quadratic;
	float cutOff;
	float outerCutOff;
};
struct DirectLight
{
	vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
struct PointLight
{
	vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
	float constant;
	float linear;
	float quadratic;
};

uniform SpotLight spotLight;
uniform DirectLight directLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];

uniform vec3 viewPos;
uniform Material material;

vec3 CalcDirectLight(DirectLight light, vec3 normal, vec3 viewDir);  
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
void main()
{
	vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

	vec3 result = CalcDirectLight(directLight, norm, viewDir);

    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);

	result += CalcSpotLight(spotLight, norm, FragPos, viewDir);

	//emission
	//result += vec3(texture(material.emission, TexCoords));
	

	color = vec4(result, 1.0f);
}
vec3 CalcDirectLight(DirectLight light, vec3 normal, vec3 viewDir)
{
	vec4 diff_texel = texture2D(material.texture_diffuse, TexCoords);
	
	vec3 lightDir = normalize(-light.direction);

	//ambient
	vec3 ambient =  light.ambient * diff_texel.rgb * material.ambient;
	
	//diffuse
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse =  light.diffuse * diff * diff_texel.rgb * material.diffuse;

	//specular
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular =  light.specular * spec * diff_texel.rgb * material.specular;

	return (ambient + diffuse + specular);
}
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec4 diff_texel = texture2D(material.texture_diffuse, TexCoords);
	
	vec3 lightDir = normalize(light.position - FragPos);

	//ambient
	vec3 ambient =  light.ambient * diff_texel.rgb * material.ambient;
	
	//diffuse
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse =  light.diffuse * diff * diff_texel.rgb * material.diffuse;
	
	//specular
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular =  light.specular * spec * diff_texel.rgb * material.specular;

	//attenuation
	float distance = length(light.position - FragPos);
	float attenuation = 1.0f / (light.constant + light.linear*distance +light.quadratic*(distance*distance));	

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return (ambient + diffuse + specular);
}
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec4 diff_texel = texture2D(material.texture_diffuse, TexCoords);

	vec3 lightDir = normalize(light.position - fragPos);
	
	//ambient
	vec3 ambient =  light.ambient * diff_texel.rgb * material.ambient;
	
    //diffuse
    float diff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse =  light.diffuse * diff * diff_texel.rgb * material.diffuse;
	
	//specular
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular =  light.specular * spec * diff_texel.rgb * material.specular;
	
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
    // Spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
   
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}