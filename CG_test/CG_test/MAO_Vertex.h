float cubeVertices[] = {
	// Back face
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, // Bottom-left
	0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f, // top-right
	0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, // bottom-right         
	0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f, // top-right
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, // top-left
	// Front face
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom-left
	0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, // bottom-right
	0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // top-right
	0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // top-right
	-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // top-left
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom-left
	// Left face
	-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-right
	-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-left
	-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom-left
	-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom-left
	-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom-right
	-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-right
	// Right face
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-left
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom-right
	0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-right         
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom-right
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-left
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom-left     
	// Bottom face
	-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, // top-right
	0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f, // top-left
	0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, // bottom-left
	0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, // bottom-left
	-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, // bottom-right
	-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, // top-right
	// Top face
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // top-left
	0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom-right
	0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // top-right     
	0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom-right
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // top-left
	-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f  // bottom-left        
};
float ballVertex[] =
{
	-7.54979e-008 ,-1 ,-1.13999e-014 ,
	-7.18028e-008 ,-1 ,-2.33301e-008 ,
	-6.10791e-008 ,-1 ,-4.43765e-008 ,
	-4.43765e-008 ,-1 ,-6.10791e-008 ,
	-2.33301e-008 ,-1 ,-7.18028e-008 ,
	5.69993e-015 ,-1 ,-7.54979e-008 ,
	2.33301e-008 ,-1 ,-7.18028e-008 ,
	4.43766e-008 ,-1 ,-6.10791e-008 ,
	6.10791e-008 ,-1 ,-4.43766e-008 ,
	7.18028e-008 ,-1 ,-2.33301e-008 ,
	7.54979e-008 ,-1 ,0 ,
	7.18028e-008 ,-1 ,2.33301e-008 ,
	6.10791e-008 ,-1 ,4.43766e-008 ,
	4.43766e-008 ,-1 ,6.10791e-008 ,
	2.33301e-008 ,-1 ,7.18028e-008 ,
	5.69993e-015 ,-1 ,7.54979e-008 ,
	-2.33301e-008 ,-1 ,7.18028e-008 ,
	-4.43765e-008 ,-1 ,6.10791e-008 ,
	-6.10791e-008 ,-1 ,4.43765e-008 ,
	-7.18028e-008 ,-1 ,2.33301e-008 ,
	-0.156434 ,-0.987688 ,-2.3621e-008 ,
	-0.148778 ,-0.987688 ,-0.0483409 ,
	-0.126558 ,-0.987688 ,-0.0919499 ,
	-0.0919499 ,-0.987688 ,-0.126558 ,
	-0.0483409 ,-0.987688 ,-0.148778 ,
	1.18105e-008 ,-0.987688 ,-0.156434 ,
	0.0483409 ,-0.987688 ,-0.148778 ,
	0.0919499 ,-0.987688 ,-0.126558 ,
	0.126558 ,-0.987688 ,-0.0919499 ,
	0.148778 ,-0.987688 ,-0.0483409 ,
	0.156434 ,-0.987688 ,0 ,
	0.148778 ,-0.987688 ,0.0483409 ,
	0.126558 ,-0.987688 ,0.0919499 ,
	0.0919499 ,-0.987688 ,0.126558 ,
	0.0483409 ,-0.987688 ,0.148778 ,
	1.18105e-008 ,-0.987688 ,0.156434 ,
	-0.0483409 ,-0.987688 ,0.148778 ,
	-0.0919499 ,-0.987688 ,0.126558 ,
	-0.126558 ,-0.987688 ,0.0919499 ,
	-0.148778 ,-0.987688 ,0.0483409 ,
	-0.309017 ,-0.951057 ,-4.66603e-008 ,
	-0.293893 ,-0.951057 ,-0.0954915 ,
	-0.25 ,-0.951057 ,-0.181636 ,
	-0.181636 ,-0.951057 ,-0.25 ,
	-0.0954915 ,-0.951057 ,-0.293893 ,
	2.33301e-008 ,-0.951057 ,-0.309017 ,
	0.0954915 ,-0.951057 ,-0.293893 ,
	0.181636 ,-0.951057 ,-0.25 ,
	0.25 ,-0.951057 ,-0.181636 ,
	0.293893 ,-0.951057 ,-0.0954915 ,
	0.309017 ,-0.951057 ,0 ,
	0.293893 ,-0.951057 ,0.0954915 ,
	0.25 ,-0.951057 ,0.181636 ,
	0.181636 ,-0.951057 ,0.25 ,
	0.0954915 ,-0.951057 ,0.293893 ,
	2.33301e-008 ,-0.951057 ,0.309017 ,
	-0.0954915 ,-0.951057 ,0.293893 ,
	-0.181636 ,-0.951057 ,0.25 ,
	-0.25 ,-0.951057 ,0.181636 ,
	-0.293893 ,-0.951057 ,0.0954915 ,
	-0.453991 ,-0.891007 ,-6.85507e-008 ,
	-0.431771 ,-0.891007 ,-0.140291 ,
	-0.367286 ,-0.891007 ,-0.266849 ,
	-0.266849 ,-0.891007 ,-0.367286 ,
	-0.140291 ,-0.891007 ,-0.431771 ,
	3.42753e-008 ,-0.891007 ,-0.453991 ,
	0.140291 ,-0.891007 ,-0.431771 ,
	0.266849 ,-0.891007 ,-0.367286 ,
	0.367286 ,-0.891007 ,-0.266849 ,
	0.431771 ,-0.891007 ,-0.140291 ,
	0.453991 ,-0.891007 ,0 ,
	0.431771 ,-0.891007 ,0.140291 ,
	0.367286 ,-0.891007 ,0.266849 ,
	0.266849 ,-0.891007 ,0.367286 ,
	0.140291 ,-0.891007 ,0.431771 ,
	3.42753e-008 ,-0.891007 ,0.453991 ,
	-0.140291 ,-0.891007 ,0.431771 ,
	-0.266849 ,-0.891007 ,0.367286 ,
	-0.367286 ,-0.891007 ,0.266849 ,
	-0.431771 ,-0.891007 ,0.140291 ,
	-0.587785 ,-0.809017 ,-8.87531e-008 ,
	-0.559017 ,-0.809017 ,-0.181636 ,
	-0.475528 ,-0.809017 ,-0.345491 ,
	-0.345491 ,-0.809017 ,-0.475528 ,
	-0.181636 ,-0.809017 ,-0.559017 ,
	4.43766e-008 ,-0.809017 ,-0.587785 ,
	0.181636 ,-0.809017 ,-0.559017 ,
	0.345492 ,-0.809017 ,-0.475528 ,
	0.475528 ,-0.809017 ,-0.345492 ,
	0.559017 ,-0.809017 ,-0.181636 ,
	0.587785 ,-0.809017 ,0 ,
	0.559017 ,-0.809017 ,0.181636 ,
	0.475528 ,-0.809017 ,0.345492 ,
	0.345492 ,-0.809017 ,0.475528 ,
	0.181636 ,-0.809017 ,0.559017 ,
	4.43766e-008 ,-0.809017 ,0.587785 ,
	-0.181636 ,-0.809017 ,0.559017 ,
	-0.345491 ,-0.809017 ,0.475528 ,
	-0.475528 ,-0.809017 ,0.345491 ,
	-0.559017 ,-0.809017 ,0.181636 ,
	-0.707107 ,-0.707107 ,-1.0677e-007 ,
	-0.672499 ,-0.707107 ,-0.218508 ,
	-0.572061 ,-0.707107 ,-0.415627 ,
	-0.415627 ,-0.707107 ,-0.572061 ,
	-0.218508 ,-0.707107 ,-0.672499 ,
	5.33851e-008 ,-0.707107 ,-0.707107 ,
	0.218508 ,-0.707107 ,-0.672499 ,
	0.415627 ,-0.707107 ,-0.572061 ,
	0.572061 ,-0.707107 ,-0.415627 ,
	0.672499 ,-0.707107 ,-0.218508 ,
	0.707107 ,-0.707107 ,0 ,
	0.672499 ,-0.707107 ,0.218508 ,
	0.572061 ,-0.707107 ,0.415627 ,
	0.415627 ,-0.707107 ,0.572061 ,
	0.218508 ,-0.707107 ,0.672499 ,
	5.33851e-008 ,-0.707107 ,0.707107 ,
	-0.218508 ,-0.707107 ,0.672499 ,
	-0.415627 ,-0.707107 ,0.572061 ,
	-0.572061 ,-0.707107 ,0.415627 ,
	-0.672499 ,-0.707107 ,0.218508 ,
	-0.809017 ,-0.587785 ,-1.22158e-007 ,
	-0.769421 ,-0.587785 ,-0.25 ,
	-0.654509 ,-0.587785 ,-0.475528 ,
	-0.475528 ,-0.587785 ,-0.654509 ,
	-0.25 ,-0.587785 ,-0.769421 ,
	6.10791e-008 ,-0.587785 ,-0.809017 ,
	0.25 ,-0.587785 ,-0.769421 ,
	0.475528 ,-0.587785 ,-0.654509 ,
	0.654509 ,-0.587785 ,-0.475528 ,
	0.769421 ,-0.587785 ,-0.25 ,
	0.809017 ,-0.587785 ,0 ,
	0.769421 ,-0.587785 ,0.25 ,
	0.654509 ,-0.587785 ,0.475528 ,
	0.475528 ,-0.587785 ,0.654509 ,
	0.25 ,-0.587785 ,0.769421 ,
	6.10791e-008 ,-0.587785 ,0.809017 ,
	-0.25 ,-0.587785 ,0.769421 ,
	-0.475528 ,-0.587785 ,0.654509 ,
	-0.654509 ,-0.587785 ,0.475528 ,
	-0.769421 ,-0.587785 ,0.25 ,
	-0.891007 ,-0.45399 ,-1.34538e-007 ,
	-0.847398 ,-0.45399 ,-0.275336 ,
	-0.72084 ,-0.45399 ,-0.52372 ,
	-0.52372 ,-0.45399 ,-0.720839 ,
	-0.275336 ,-0.45399 ,-0.847398 ,
	6.72691e-008 ,-0.45399 ,-0.891007 ,
	0.275336 ,-0.45399 ,-0.847398 ,
	0.523721 ,-0.45399 ,-0.720839 ,
	0.720839 ,-0.45399 ,-0.523721 ,
	0.847398 ,-0.45399 ,-0.275336 ,
	0.891007 ,-0.45399 ,0 ,
	0.847398 ,-0.45399 ,0.275336 ,
	0.720839 ,-0.45399 ,0.523721 ,
	0.523721 ,-0.45399 ,0.720839 ,
	0.275336 ,-0.45399 ,0.847398 ,
	6.72691e-008 ,-0.45399 ,0.891007 ,
	-0.275336 ,-0.45399 ,0.847398 ,
	-0.52372 ,-0.45399 ,0.720839 ,
	-0.72084 ,-0.45399 ,0.52372 ,
	-0.847398 ,-0.45399 ,0.275336 ,
	-0.951057 ,-0.309017 ,-1.43606e-007 ,
	-0.904508 ,-0.309017 ,-0.293893 ,
	-0.769421 ,-0.309017 ,-0.559017 ,
	-0.559017 ,-0.309017 ,-0.769421 ,
	-0.293893 ,-0.309017 ,-0.904509 ,
	7.18028e-008 ,-0.309017 ,-0.951057 ,
	0.293893 ,-0.309017 ,-0.904509 ,
	0.559017 ,-0.309017 ,-0.769421 ,
	0.769421 ,-0.309017 ,-0.559017 ,
	0.904509 ,-0.309017 ,-0.293893 ,
	0.951057 ,-0.309017 ,0 ,
	0.904509 ,-0.309017 ,0.293893 ,
	0.769421 ,-0.309017 ,0.559017 ,
	0.559017 ,-0.309017 ,0.769421 ,
	0.293893 ,-0.309017 ,0.904509 ,
	7.18028e-008 ,-0.309017 ,0.951057 ,
	-0.293893 ,-0.309017 ,0.904509 ,
	-0.559017 ,-0.309017 ,0.769421 ,
	-0.769421 ,-0.309017 ,0.559017 ,
	-0.904508 ,-0.309017 ,0.293893 ,
	-0.987688 ,-0.156434 ,-1.49137e-007 ,
	-0.939347 ,-0.156434 ,-0.305213 ,
	-0.799057 ,-0.156434 ,-0.580549 ,
	-0.580549 ,-0.156434 ,-0.799057 ,
	-0.305212 ,-0.156434 ,-0.939348 ,
	7.45684e-008 ,-0.156434 ,-0.987688 ,
	0.305212 ,-0.156434 ,-0.939348 ,
	0.580549 ,-0.156434 ,-0.799057 ,
	0.799057 ,-0.156434 ,-0.580549 ,
	0.939348 ,-0.156434 ,-0.305212 ,
	0.987688 ,-0.156434 ,0 ,
	0.939348 ,-0.156434 ,0.305212 ,
	0.799057 ,-0.156434 ,0.580549 ,
	0.580549 ,-0.156434 ,0.799057 ,
	0.305212 ,-0.156434 ,0.939348 ,
	7.45684e-008 ,-0.156434 ,0.987688 ,
	-0.305212 ,-0.156434 ,0.939348 ,
	-0.580549 ,-0.156434 ,0.799057 ,
	-0.799057 ,-0.156434 ,0.580549 ,
	-0.939347 ,-0.156434 ,0.305213 ,
	-1 ,0 ,-1.50996e-007 ,
	-0.951056 ,0 ,-0.309017 ,
	-0.809017 ,0 ,-0.587785 ,
	-0.587785 ,0 ,-0.809017 ,
	-0.309017 ,0 ,-0.951057 ,
	7.54979e-008 ,0 ,-1 ,
	0.309017 ,0 ,-0.951057 ,
	0.587785 ,0 ,-0.809017 ,
	0.809017 ,0 ,-0.587785 ,
	0.951057 ,0 ,-0.309017 ,
	1 ,0 ,0 ,
	0.951057 ,0 ,0.309017 ,
	0.809017 ,0 ,0.587785 ,
	0.587785 ,0 ,0.809017 ,
	0.309017 ,0 ,0.951057 ,
	7.54979e-008 ,0 ,1 ,
	-0.309017 ,0 ,0.951057 ,
	-0.587785 ,0 ,0.809017 ,
	-0.809017 ,0 ,0.587785 ,
	-0.951056 ,0 ,0.309017 ,
	-0.987688 ,0.156434 ,-1.49137e-007 ,
	-0.939347 ,0.156434 ,-0.305213 ,
	-0.799057 ,0.156434 ,-0.580549 ,
	-0.580549 ,0.156434 ,-0.799057 ,
	-0.305212 ,0.156434 ,-0.939348 ,
	7.45684e-008 ,0.156434 ,-0.987688 ,
	0.305212 ,0.156434 ,-0.939348 ,
	0.580549 ,0.156434 ,-0.799057 ,
	0.799057 ,0.156434 ,-0.580549 ,
	0.939348 ,0.156434 ,-0.305212 ,
	0.987688 ,0.156434 ,0 ,
	0.939348 ,0.156434 ,0.305212 ,
	0.799057 ,0.156434 ,0.580549 ,
	0.580549 ,0.156434 ,0.799057 ,
	0.305212 ,0.156434 ,0.939348 ,
	7.45684e-008 ,0.156434 ,0.987688 ,
	-0.305212 ,0.156434 ,0.939348 ,
	-0.580549 ,0.156434 ,0.799057 ,
	-0.799057 ,0.156434 ,0.580549 ,
	-0.939347 ,0.156434 ,0.305213 ,
	-0.951057 ,0.309017 ,-1.43606e-007 ,
	-0.904508 ,0.309017 ,-0.293893 ,
	-0.769421 ,0.309017 ,-0.559017 ,
	-0.559017 ,0.309017 ,-0.769421 ,
	-0.293893 ,0.309017 ,-0.904509 ,
	7.18028e-008 ,0.309017 ,-0.951057 ,
	0.293893 ,0.309017 ,-0.904509 ,
	0.559017 ,0.309017 ,-0.769421 ,
	0.769421 ,0.309017 ,-0.559017 ,
	0.904509 ,0.309017 ,-0.293893 ,
	0.951057 ,0.309017 ,0 ,
	0.904509 ,0.309017 ,0.293893 ,
	0.769421 ,0.309017 ,0.559017 ,
	0.559017 ,0.309017 ,0.769421 ,
	0.293893 ,0.309017 ,0.904509 ,
	7.18028e-008 ,0.309017 ,0.951057 ,
	-0.293893 ,0.309017 ,0.904509 ,
	-0.559017 ,0.309017 ,0.769421 ,
	-0.769421 ,0.309017 ,0.559017 ,
	-0.904508 ,0.309017 ,0.293893 ,
	-0.891007 ,0.45399 ,-1.34538e-007 ,
	-0.847398 ,0.45399 ,-0.275336 ,
	-0.72084 ,0.45399 ,-0.52372 ,
	-0.52372 ,0.45399 ,-0.720839 ,
	-0.275336 ,0.45399 ,-0.847398 ,
	6.72691e-008 ,0.45399 ,-0.891007 ,
	0.275336 ,0.45399 ,-0.847398 ,
	0.523721 ,0.45399 ,-0.720839 ,
	0.720839 ,0.45399 ,-0.523721 ,
	0.847398 ,0.45399 ,-0.275336 ,
	0.891007 ,0.45399 ,0 ,
	0.847398 ,0.45399 ,0.275336 ,
	0.720839 ,0.45399 ,0.523721 ,
	0.523721 ,0.45399 ,0.720839 ,
	0.275336 ,0.45399 ,0.847398 ,
	6.72691e-008 ,0.45399 ,0.891007 ,
	-0.275336 ,0.45399 ,0.847398 ,
	-0.52372 ,0.45399 ,0.720839 ,
	-0.72084 ,0.45399 ,0.52372 ,
	-0.847398 ,0.45399 ,0.275336 ,
	-0.809017 ,0.587785 ,-1.22158e-007 ,
	-0.769421 ,0.587785 ,-0.25 ,
	-0.654509 ,0.587785 ,-0.475528 ,
	-0.475528 ,0.587785 ,-0.654509 ,
	-0.25 ,0.587785 ,-0.769421 ,
	6.10791e-008 ,0.587785 ,-0.809017 ,
	0.25 ,0.587785 ,-0.769421 ,
	0.475528 ,0.587785 ,-0.654509 ,
	0.654509 ,0.587785 ,-0.475528 ,
	0.769421 ,0.587785 ,-0.25 ,
	0.809017 ,0.587785 ,0 ,
	0.769421 ,0.587785 ,0.25 ,
	0.654509 ,0.587785 ,0.475528 ,
	0.475528 ,0.587785 ,0.654509 ,
	0.25 ,0.587785 ,0.769421 ,
	6.10791e-008 ,0.587785 ,0.809017 ,
	-0.25 ,0.587785 ,0.769421 ,
	-0.475528 ,0.587785 ,0.654509 ,
	-0.654509 ,0.587785 ,0.475528 ,
	-0.769421 ,0.587785 ,0.25 ,
	-0.707107 ,0.707107 ,-1.0677e-007 ,
	-0.672499 ,0.707107 ,-0.218508 ,
	-0.572061 ,0.707107 ,-0.415627 ,
	-0.415627 ,0.707107 ,-0.572061 ,
	-0.218508 ,0.707107 ,-0.672499 ,
	5.33851e-008 ,0.707107 ,-0.707107 ,
	0.218508 ,0.707107 ,-0.672499 ,
	0.415627 ,0.707107 ,-0.572061 ,
	0.572061 ,0.707107 ,-0.415627 ,
	0.672499 ,0.707107 ,-0.218508 ,
	0.707107 ,0.707107 ,0 ,
	0.672499 ,0.707107 ,0.218508 ,
	0.572061 ,0.707107 ,0.415627 ,
	0.415627 ,0.707107 ,0.572061 ,
	0.218508 ,0.707107 ,0.672499 ,
	5.33851e-008 ,0.707107 ,0.707107 ,
	-0.218508 ,0.707107 ,0.672499 ,
	-0.415627 ,0.707107 ,0.572061 ,
	-0.572061 ,0.707107 ,0.415627 ,
	-0.672499 ,0.707107 ,0.218508 ,
	-0.587785 ,0.809017 ,-8.87531e-008 ,
	-0.559017 ,0.809017 ,-0.181636 ,
	-0.475528 ,0.809017 ,-0.345491 ,
	-0.345491 ,0.809017 ,-0.475528 ,
	-0.181636 ,0.809017 ,-0.559017 ,
	4.43766e-008 ,0.809017 ,-0.587785 ,
	0.181636 ,0.809017 ,-0.559017 ,
	0.345492 ,0.809017 ,-0.475528 ,
	0.475528 ,0.809017 ,-0.345492 ,
	0.559017 ,0.809017 ,-0.181636 ,
	0.587785 ,0.809017 ,0 ,
	0.559017 ,0.809017 ,0.181636 ,
	0.475528 ,0.809017 ,0.345492 ,
	0.345492 ,0.809017 ,0.475528 ,
	0.181636 ,0.809017 ,0.559017 ,
	4.43766e-008 ,0.809017 ,0.587785 ,
	-0.181636 ,0.809017 ,0.559017 ,
	-0.345491 ,0.809017 ,0.475528 ,
	-0.475528 ,0.809017 ,0.345491 ,
	-0.559017 ,0.809017 ,0.181636 ,
	-0.453991 ,0.891007 ,-6.85507e-008 ,
	-0.431771 ,0.891007 ,-0.140291 ,
	-0.367286 ,0.891007 ,-0.266849 ,
	-0.266849 ,0.891007 ,-0.367286 ,
	-0.140291 ,0.891007 ,-0.431771 ,
	3.42753e-008 ,0.891007 ,-0.453991 ,
	0.140291 ,0.891007 ,-0.431771 ,
	0.266849 ,0.891007 ,-0.367286 ,
	0.367286 ,0.891007 ,-0.266849 ,
	0.431771 ,0.891007 ,-0.140291 ,
	0.453991 ,0.891007 ,0 ,
	0.431771 ,0.891007 ,0.140291 ,
	0.367286 ,0.891007 ,0.266849 ,
	0.266849 ,0.891007 ,0.367286 ,
	0.140291 ,0.891007 ,0.431771 ,
	3.42753e-008 ,0.891007 ,0.453991 ,
	-0.140291 ,0.891007 ,0.431771 ,
	-0.266849 ,0.891007 ,0.367286 ,
	-0.367286 ,0.891007 ,0.266849 ,
	-0.431771 ,0.891007 ,0.140291 ,
	-0.309017 ,0.951057 ,-4.66603e-008 ,
	-0.293893 ,0.951057 ,-0.0954915 ,
	-0.25 ,0.951057 ,-0.181636 ,
	-0.181636 ,0.951057 ,-0.25 ,
	-0.0954915 ,0.951057 ,-0.293893 ,
	2.33301e-008 ,0.951057 ,-0.309017 ,
	0.0954915 ,0.951057 ,-0.293893 ,
	0.181636 ,0.951057 ,-0.25 ,
	0.25 ,0.951057 ,-0.181636 ,
	0.293893 ,0.951057 ,-0.0954915 ,
	0.309017 ,0.951057 ,0 ,
	0.293893 ,0.951057 ,0.0954915 ,
	0.25 ,0.951057 ,0.181636 ,
	0.181636 ,0.951057 ,0.25 ,
	0.0954915 ,0.951057 ,0.293893 ,
	2.33301e-008 ,0.951057 ,0.309017 ,
	-0.0954915 ,0.951057 ,0.293893 ,
	-0.181636 ,0.951057 ,0.25 ,
	-0.25 ,0.951057 ,0.181636 ,
	-0.293893 ,0.951057 ,0.0954915 ,
	-0.156434 ,0.987688 ,-2.3621e-008 ,
	-0.148778 ,0.987688 ,-0.0483409 ,
	-0.126558 ,0.987688 ,-0.0919499 ,
	-0.0919499 ,0.987688 ,-0.126558 ,
	-0.0483409 ,0.987688 ,-0.148778 ,
	1.18105e-008 ,0.987688 ,-0.156434 ,
	0.0483409 ,0.987688 ,-0.148778 ,
	0.0919499 ,0.987688 ,-0.126558 ,
	0.126558 ,0.987688 ,-0.0919499 ,
	0.148778 ,0.987688 ,-0.0483409 ,
	0.156434 ,0.987688 ,0 ,
	0.148778 ,0.987688 ,0.0483409 ,
	0.126558 ,0.987688 ,0.0919499 ,
	0.0919499 ,0.987688 ,0.126558 ,
	0.0483409 ,0.987688 ,0.148778 ,
	1.18105e-008 ,0.987688 ,0.156434 ,
	-0.0483409 ,0.987688 ,0.148778 ,
	-0.0919499 ,0.987688 ,0.126558 ,
	-0.126558 ,0.987688 ,0.0919499 ,
	-0.148778 ,0.987688 ,0.0483409 ,
	-7.54979e-008 ,1 ,-1.13999e-014 ,
	-7.18028e-008 ,1 ,-2.33301e-008 ,
	-6.10791e-008 ,1 ,-4.43765e-008 ,
	-4.43765e-008 ,1 ,-6.10791e-008 ,
	-2.33301e-008 ,1 ,-7.18028e-008 ,
	5.69993e-015 ,1 ,-7.54979e-008 ,
	2.33301e-008 ,1 ,-7.18028e-008 ,
	4.43766e-008 ,1 ,-6.10791e-008 ,
	6.10791e-008 ,1 ,-4.43766e-008 ,
	7.18028e-008 ,1 ,-2.33301e-008 ,
	7.54979e-008 ,1 ,0 ,
	7.18028e-008 ,1 ,2.33301e-008 ,
	6.10791e-008 ,1 ,4.43766e-008 ,
	4.43766e-008 ,1 ,6.10791e-008 ,
	2.33301e-008 ,1 ,7.18028e-008 ,
	5.69993e-015 ,1 ,7.54979e-008 ,
	-2.33301e-008 ,1 ,7.18028e-008 ,
	-4.43765e-008 ,1 ,6.10791e-008 ,
	-6.10791e-008 ,1 ,4.43765e-008 ,
	-7.18028e-008 ,1 ,2.33301e-008 ,
};
unsigned int ballIndex[] = 
{
	0, 20, 1,
	1, 20, 21,
	1, 21, 2,
	2, 21, 22,
	2, 22, 3,
	3, 22, 23,
	3, 23, 4,
	4, 23, 24,
	4, 24, 5,
	5, 24, 25,
	5, 25, 6,
	6, 25, 26,
	6, 26, 7,
	7, 26, 27,
	7, 27, 8,
	8, 27, 28,
	8, 28, 9,
	9, 28, 29,
	9, 29, 10,
	10, 29, 30,
	10, 30, 11,
	11, 30, 31,
	11, 31, 12,
	12, 31, 32,
	12, 32, 13,
	13, 32, 33,
	13, 33, 14,
	14, 33, 34,
	14, 34, 15,
	15, 34, 35,
	15, 35, 16,
	16, 35, 36,
	16, 36, 17,
	17, 36, 37,
	17, 37, 18,
	18, 37, 38,
	18, 38, 19,
	19, 38, 39,
	19, 39, 0,
	0, 39, 20,
	20, 40, 21,
	21, 40, 41,
	21, 41, 22,
	22, 41, 42,
	22, 42, 23,
	23, 42, 43,
	23, 43, 24,
	24, 43, 44,
	24, 44, 25,
	25, 44, 45,
	25, 45, 26,
	26, 45, 46,
	26, 46, 27,
	27, 46, 47,
	27, 47, 28,
	28, 47, 48,
	28, 48, 29,
	29, 48, 49,
	29, 49, 30,
	30, 49, 50,
	30, 50, 31,
	31, 50, 51,
	31, 51, 32,
	32, 51, 52,
	32, 52, 33,
	33, 52, 53,
	33, 53, 34,
	34, 53, 54,
	34, 54, 35,
	35, 54, 55,
	35, 55, 36,
	36, 55, 56,
	36, 56, 37,
	37, 56, 57,
	37, 57, 38,
	38, 57, 58,
	38, 58, 39,
	39, 58, 59,
	39, 59, 20,
	20, 59, 40,
	40, 60, 41,
	41, 60, 61,
	41, 61, 42,
	42, 61, 62,
	42, 62, 43,
	43, 62, 63,
	43, 63, 44,
	44, 63, 64,
	44, 64, 45,
	45, 64, 65,
	45, 65, 46,
	46, 65, 66,
	46, 66, 47,
	47, 66, 67,
	47, 67, 48,
	48, 67, 68,
	48, 68, 49,
	49, 68, 69,
	49, 69, 50,
	50, 69, 70,
	50, 70, 51,
	51, 70, 71,
	51, 71, 52,
	52, 71, 72,
	52, 72, 53,
	53, 72, 73,
	53, 73, 54,
	54, 73, 74,
	54, 74, 55,
	55, 74, 75,
	55, 75, 56,
	56, 75, 76,
	56, 76, 57,
	57, 76, 77,
	57, 77, 58,
	58, 77, 78,
	58, 78, 59,
	59, 78, 79,
	59, 79, 40,
	40, 79, 60,
	60, 80, 61,
	61, 80, 81,
	61, 81, 62,
	62, 81, 82,
	62, 82, 63,
	63, 82, 83,
	63, 83, 64,
	64, 83, 84,
	64, 84, 65,
	65, 84, 85,
	65, 85, 66,
	66, 85, 86,
	66, 86, 67,
	67, 86, 87,
	67, 87, 68,
	68, 87, 88,
	68, 88, 69,
	69, 88, 89,
	69, 89, 70,
	70, 89, 90,
	70, 90, 71,
	71, 90, 91,
	71, 91, 72,
	72, 91, 92,
	72, 92, 73,
	73, 92, 93,
	73, 93, 74,
	74, 93, 94,
	74, 94, 75,
	75, 94, 95,
	75, 95, 76,
	76, 95, 96,
	76, 96, 77,
	77, 96, 97,
	77, 97, 78,
	78, 97, 98,
	78, 98, 79,
	79, 98, 99,
	79, 99, 60,
	60, 99, 80,
	80, 100, 81,
	81, 100, 101,
	81, 101, 82,
	82, 101, 102,
	82, 102, 83,
	83, 102, 103,
	83, 103, 84,
	84, 103, 104,
	84, 104, 85,
	85, 104, 105,
	85, 105, 86,
	86, 105, 106,
	86, 106, 87,
	87, 106, 107,
	87, 107, 88,
	88, 107, 108,
	88, 108, 89,
	89, 108, 109,
	89, 109, 90,
	90, 109, 110,
	90, 110, 91,
	91, 110, 111,
	91, 111, 92,
	92, 111, 112,
	92, 112, 93,
	93, 112, 113,
	93, 113, 94,
	94, 113, 114,
	94, 114, 95,
	95, 114, 115,
	95, 115, 96,
	96, 115, 116,
	96, 116, 97,
	97, 116, 117,
	97, 117, 98,
	98, 117, 118,
	98, 118, 99,
	99, 118, 119,
	99, 119, 80,
	80, 119, 100,
	100, 120, 101,
	101, 120, 121,
	101, 121, 102,
	102, 121, 122,
	102, 122, 103,
	103, 122, 123,
	103, 123, 104,
	104, 123, 124,
	104, 124, 105,
	105, 124, 125,
	105, 125, 106,
	106, 125, 126,
	106, 126, 107,
	107, 126, 127,
	107, 127, 108,
	108, 127, 128,
	108, 128, 109,
	109, 128, 129,
	109, 129, 110,
	110, 129, 130,
	110, 130, 111,
	111, 130, 131,
	111, 131, 112,
	112, 131, 132,
	112, 132, 113,
	113, 132, 133,
	113, 133, 114,
	114, 133, 134,
	114, 134, 115,
	115, 134, 135,
	115, 135, 116,
	116, 135, 136,
	116, 136, 117,
	117, 136, 137,
	117, 137, 118,
	118, 137, 138,
	118, 138, 119,
	119, 138, 139,
	119, 139, 100,
	100, 139, 120,
	120, 140, 121,
	121, 140, 141,
	121, 141, 122,
	122, 141, 142,
	122, 142, 123,
	123, 142, 143,
	123, 143, 124,
	124, 143, 144,
	124, 144, 125,
	125, 144, 145,
	125, 145, 126,
	126, 145, 146,
	126, 146, 127,
	127, 146, 147,
	127, 147, 128,
	128, 147, 148,
	128, 148, 129,
	129, 148, 149,
	129, 149, 130,
	130, 149, 150,
	130, 150, 131,
	131, 150, 151,
	131, 151, 132,
	132, 151, 152,
	132, 152, 133,
	133, 152, 153,
	133, 153, 134,
	134, 153, 154,
	134, 154, 135,
	135, 154, 155,
	135, 155, 136,
	136, 155, 156,
	136, 156, 137,
	137, 156, 157,
	137, 157, 138,
	138, 157, 158,
	138, 158, 139,
	139, 158, 159,
	139, 159, 120,
	120, 159, 140,
	140, 160, 141,
	141, 160, 161,
	141, 161, 142,
	142, 161, 162,
	142, 162, 143,
	143, 162, 163,
	143, 163, 144,
	144, 163, 164,
	144, 164, 145,
	145, 164, 165,
	145, 165, 146,
	146, 165, 166,
	146, 166, 147,
	147, 166, 167,
	147, 167, 148,
	148, 167, 168,
	148, 168, 149,
	149, 168, 169,
	149, 169, 150,
	150, 169, 170,
	150, 170, 151,
	151, 170, 171,
	151, 171, 152,
	152, 171, 172,
	152, 172, 153,
	153, 172, 173,
	153, 173, 154,
	154, 173, 174,
	154, 174, 155,
	155, 174, 175,
	155, 175, 156,
	156, 175, 176,
	156, 176, 157,
	157, 176, 177,
	157, 177, 158,
	158, 177, 178,
	158, 178, 159,
	159, 178, 179,
	159, 179, 140,
	140, 179, 160,
	160, 180, 161,
	161, 180, 181,
	161, 181, 162,
	162, 181, 182,
	162, 182, 163,
	163, 182, 183,
	163, 183, 164,
	164, 183, 184,
	164, 184, 165,
	165, 184, 185,
	165, 185, 166,
	166, 185, 186,
	166, 186, 167,
	167, 186, 187,
	167, 187, 168,
	168, 187, 188,
	168, 188, 169,
	169, 188, 189,
	169, 189, 170,
	170, 189, 190,
	170, 190, 171,
	171, 190, 191,
	171, 191, 172,
	172, 191, 192,
	172, 192, 173,
	173, 192, 193,
	173, 193, 174,
	174, 193, 194,
	174, 194, 175,
	175, 194, 195,
	175, 195, 176,
	176, 195, 196,
	176, 196, 177,
	177, 196, 197,
	177, 197, 178,
	178, 197, 198,
	178, 198, 179,
	179, 198, 199,
	179, 199, 160,
	160, 199, 180,
	180, 200, 181,
	181, 200, 201,
	181, 201, 182,
	182, 201, 202,
	182, 202, 183,
	183, 202, 203,
	183, 203, 184,
	184, 203, 204,
	184, 204, 185,
	185, 204, 205,
	185, 205, 186,
	186, 205, 206,
	186, 206, 187,
	187, 206, 207,
	187, 207, 188,
	188, 207, 208,
	188, 208, 189,
	189, 208, 209,
	189, 209, 190,
	190, 209, 210,
	190, 210, 191,
	191, 210, 211,
	191, 211, 192,
	192, 211, 212,
	192, 212, 193,
	193, 212, 213,
	193, 213, 194,
	194, 213, 214,
	194, 214, 195,
	195, 214, 215,
	195, 215, 196,
	196, 215, 216,
	196, 216, 197,
	197, 216, 217,
	197, 217, 198,
	198, 217, 218,
	198, 218, 199,
	199, 218, 219,
	199, 219, 180,
	180, 219, 200,
	200, 220, 201,
	201, 220, 221,
	201, 221, 202,
	202, 221, 222,
	202, 222, 203,
	203, 222, 223,
	203, 223, 204,
	204, 223, 224,
	204, 224, 205,
	205, 224, 225,
	205, 225, 206,
	206, 225, 226,
	206, 226, 207,
	207, 226, 227,
	207, 227, 208,
	208, 227, 228,
	208, 228, 209,
	209, 228, 229,
	209, 229, 210,
	210, 229, 230,
	210, 230, 211,
	211, 230, 231,
	211, 231, 212,
	212, 231, 232,
	212, 232, 213,
	213, 232, 233,
	213, 233, 214,
	214, 233, 234,
	214, 234, 215,
	215, 234, 235,
	215, 235, 216,
	216, 235, 236,
	216, 236, 217,
	217, 236, 237,
	217, 237, 218,
	218, 237, 238,
	218, 238, 219,
	219, 238, 239,
	219, 239, 200,
	200, 239, 220,
	220, 240, 221,
	221, 240, 241,
	221, 241, 222,
	222, 241, 242,
	222, 242, 223,
	223, 242, 243,
	223, 243, 224,
	224, 243, 244,
	224, 244, 225,
	225, 244, 245,
	225, 245, 226,
	226, 245, 246,
	226, 246, 227,
	227, 246, 247,
	227, 247, 228,
	228, 247, 248,
	228, 248, 229,
	229, 248, 249,
	229, 249, 230,
	230, 249, 250,
	230, 250, 231,
	231, 250, 251,
	231, 251, 232,
	232, 251, 252,
	232, 252, 233,
	233, 252, 253,
	233, 253, 234,
	234, 253, 254,
	234, 254, 235,
	235, 254, 255,
	235, 255, 236,
	236, 255, 256,
	236, 256, 237,
	237, 256, 257,
	237, 257, 238,
	238, 257, 258,
	238, 258, 239,
	239, 258, 259,
	239, 259, 220,
	220, 259, 240,
	240, 260, 241,
	241, 260, 261,
	241, 261, 242,
	242, 261, 262,
	242, 262, 243,
	243, 262, 263,
	243, 263, 244,
	244, 263, 264,
	244, 264, 245,
	245, 264, 265,
	245, 265, 246,
	246, 265, 266,
	246, 266, 247,
	247, 266, 267,
	247, 267, 248,
	248, 267, 268,
	248, 268, 249,
	249, 268, 269,
	249, 269, 250,
	250, 269, 270,
	250, 270, 251,
	251, 270, 271,
	251, 271, 252,
	252, 271, 272,
	252, 272, 253,
	253, 272, 273,
	253, 273, 254,
	254, 273, 274,
	254, 274, 255,
	255, 274, 275,
	255, 275, 256,
	256, 275, 276,
	256, 276, 257,
	257, 276, 277,
	257, 277, 258,
	258, 277, 278,
	258, 278, 259,
	259, 278, 279,
	259, 279, 240,
	240, 279, 260,
	260, 280, 261,
	261, 280, 281,
	261, 281, 262,
	262, 281, 282,
	262, 282, 263,
	263, 282, 283,
	263, 283, 264,
	264, 283, 284,
	264, 284, 265,
	265, 284, 285,
	265, 285, 266,
	266, 285, 286,
	266, 286, 267,
	267, 286, 287,
	267, 287, 268,
	268, 287, 288,
	268, 288, 269,
	269, 288, 289,
	269, 289, 270,
	270, 289, 290,
	270, 290, 271,
	271, 290, 291,
	271, 291, 272,
	272, 291, 292,
	272, 292, 273,
	273, 292, 293,
	273, 293, 274,
	274, 293, 294,
	274, 294, 275,
	275, 294, 295,
	275, 295, 276,
	276, 295, 296,
	276, 296, 277,
	277, 296, 297,
	277, 297, 278,
	278, 297, 298,
	278, 298, 279,
	279, 298, 299,
	279, 299, 260,
	260, 299, 280,
	280, 300, 281,
	281, 300, 301,
	281, 301, 282,
	282, 301, 302,
	282, 302, 283,
	283, 302, 303,
	283, 303, 284,
	284, 303, 304,
	284, 304, 285,
	285, 304, 305,
	285, 305, 286,
	286, 305, 306,
	286, 306, 287,
	287, 306, 307,
	287, 307, 288,
	288, 307, 308,
	288, 308, 289,
	289, 308, 309,
	289, 309, 290,
	290, 309, 310,
	290, 310, 291,
	291, 310, 311,
	291, 311, 292,
	292, 311, 312,
	292, 312, 293,
	293, 312, 313,
	293, 313, 294,
	294, 313, 314,
	294, 314, 295,
	295, 314, 315,
	295, 315, 296,
	296, 315, 316,
	296, 316, 297,
	297, 316, 317,
	297, 317, 298,
	298, 317, 318,
	298, 318, 299,
	299, 318, 319,
	299, 319, 280,
	280, 319, 300,
	300, 320, 301,
	301, 320, 321,
	301, 321, 302,
	302, 321, 322,
	302, 322, 303,
	303, 322, 323,
	303, 323, 304,
	304, 323, 324,
	304, 324, 305,
	305, 324, 325,
	305, 325, 306,
	306, 325, 326,
	306, 326, 307,
	307, 326, 327,
	307, 327, 308,
	308, 327, 328,
	308, 328, 309,
	309, 328, 329,
	309, 329, 310,
	310, 329, 330,
	310, 330, 311,
	311, 330, 331,
	311, 331, 312,
	312, 331, 332,
	312, 332, 313,
	313, 332, 333,
	313, 333, 314,
	314, 333, 334,
	314, 334, 315,
	315, 334, 335,
	315, 335, 316,
	316, 335, 336,
	316, 336, 317,
	317, 336, 337,
	317, 337, 318,
	318, 337, 338,
	318, 338, 319,
	319, 338, 339,
	319, 339, 300,
	300, 339, 320,
	320, 340, 321,
	321, 340, 341,
	321, 341, 322,
	322, 341, 342,
	322, 342, 323,
	323, 342, 343,
	323, 343, 324,
	324, 343, 344,
	324, 344, 325,
	325, 344, 345,
	325, 345, 326,
	326, 345, 346,
	326, 346, 327,
	327, 346, 347,
	327, 347, 328,
	328, 347, 348,
	328, 348, 329,
	329, 348, 349,
	329, 349, 330,
	330, 349, 350,
	330, 350, 331,
	331, 350, 351,
	331, 351, 332,
	332, 351, 352,
	332, 352, 333,
	333, 352, 353,
	333, 353, 334,
	334, 353, 354,
	334, 354, 335,
	335, 354, 355,
	335, 355, 336,
	336, 355, 356,
	336, 356, 337,
	337, 356, 357,
	337, 357, 338,
	338, 357, 358,
	338, 358, 339,
	339, 358, 359,
	339, 359, 320,
	320, 359, 340,
	340, 360, 341,
	341, 360, 361,
	341, 361, 342,
	342, 361, 362,
	342, 362, 343,
	343, 362, 363,
	343, 363, 344,
	344, 363, 364,
	344, 364, 345,
	345, 364, 365,
	345, 365, 346,
	346, 365, 366,
	346, 366, 347,
	347, 366, 367,
	347, 367, 348,
	348, 367, 368,
	348, 368, 349,
	349, 368, 369,
	349, 369, 350,
	350, 369, 370,
	350, 370, 351,
	351, 370, 371,
	351, 371, 352,
	352, 371, 372,
	352, 372, 353,
	353, 372, 373,
	353, 373, 354,
	354, 373, 374,
	354, 374, 355,
	355, 374, 375,
	355, 375, 356,
	356, 375, 376,
	356, 376, 357,
	357, 376, 377,
	357, 377, 358,
	358, 377, 378,
	358, 378, 359,
	359, 378, 379,
	359, 379, 340,
	340, 379, 360,
	360, 380, 361,
	361, 380, 381,
	361, 381, 362,
	362, 381, 382,
	362, 382, 363,
	363, 382, 383,
	363, 383, 364,
	364, 383, 384,
	364, 384, 365,
	365, 384, 385,
	365, 385, 366,
	366, 385, 386,
	366, 386, 367,
	367, 386, 387,
	367, 387, 368,
	368, 387, 388,
	368, 388, 369,
	369, 388, 389,
	369, 389, 370,
	370, 389, 390,
	370, 390, 371,
	371, 390, 391,
	371, 391, 372,
	372, 391, 392,
	372, 392, 373,
	373, 392, 393,
	373, 393, 374,
	374, 393, 394,
	374, 394, 375,
	375, 394, 395,
	375, 395, 376,
	376, 395, 396,
	376, 396, 377,
	377, 396, 397,
	377, 397, 378,
	378, 397, 398,
	378, 398, 379,
	379, 398, 399,
	379, 399, 360,
	360, 399, 380,
	380, 400, 381,
	381, 400, 401,
	381, 401, 382,
	382, 401, 402,
	382, 402, 383,
	383, 402, 403,
	383, 403, 384,
	384, 403, 404,
	384, 404, 385,
	385, 404, 405,
	385, 405, 386,
	386, 405, 406,
	386, 406, 387,
	387, 406, 407,
	387, 407, 388,
	388, 407, 408,
	388, 408, 389,
	389, 408, 409,
	389, 409, 390,
	390, 409, 410,
	390, 410, 391,
	391, 410, 411,
	391, 411, 392,
	392, 411, 412,
	392, 412, 393,
	393, 412, 413,
	393, 413, 394,
	394, 413, 414,
	394, 414, 395,
	395, 414, 415,
	395, 415, 396,
	396, 415, 416,
	396, 416, 397,
	397, 416, 417,
	397, 417, 398,
	398, 417, 418,
	398, 418, 399,
	399, 418, 419,
	399, 419, 380,
	380, 419, 400
};
float ballTextureCoordinate[] = 
{
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f
};
