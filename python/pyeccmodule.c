//BSD 3-Clause License
//
//Copyright (c) 2018, jadeblaquiere
//All rights reserved.
//
//Redistribution and use in source and binary forms, with or without
//modification, are permitted provided that the following conditions are met:
//
//* Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//* Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//* Neither the name of the copyright holder nor the names of its
//  contributors may be used to endorse or promote products derived from
//  this software without specific prior written permission.
//
//THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <gmp.h>
#include <ecc/safememory.h>
#include <pycurve.h>
#include <pyecdsa.h>
#include <pyecelgamal.h>
#include <pyfield.h>
#include <pypoint.h>
#include <Python.h>
//#include <structmember.h>

//
// Module Implementation
//

// Module Global Methods
static PyMethodDef ECC_methods[] = {
	//{"get_random_prime", get_random_prime, METH_VARARGS, "get a random n-bit prime"},
	{NULL, NULL, 0, NULL}
};

PyDoc_STRVAR(ECC_module__doc__, 
	"Elliptic Curve Cryptography (ECC) primitive math library. ECC implements "
	"the basic mathematical operations to support math in prime fields, "
	"curve parameterization and elliptic curve point operations. The "
	"fundamental math operations provide the necessary underpinnings to "
	"implement cryptographic systems like ECDH and ECDSA.");

static PyModuleDef ECC_module = {
	PyModuleDef_HEAD_INIT,
	"ECC",
	ECC_module__doc__,
	-1,
	ECC_methods
};

PyMODINIT_FUNC
PyInit_ECC(void) 
{
	PyObject* m;

    _enable_gmp_safe_clean();

	if (PyType_Ready(&FieldElementType) < 0)
		return NULL;
	if (PyType_Ready(&ECurveType) < 0)
		return NULL;
	if (PyType_Ready(&ECPointType) < 0)
		return NULL;
	if (PyType_Ready(&ECDSASignatureType) < 0)
		return NULL;
	if (PyType_Ready(&ECDSASignatureSchemeType) < 0)
		return NULL;
	if (PyType_Ready(&ECElgamalCiphertextType) < 0)
		return NULL;

	m = PyModule_Create(&ECC_module);

	if (m == NULL)
		return NULL;

	Py_INCREF(&FieldElementType);
	Py_INCREF(&ECurveType);
	Py_INCREF(&ECPointType);
	Py_INCREF(&ECDSASignatureType);
	Py_INCREF(&ECDSASignatureSchemeType);
	Py_INCREF(&ECElgamalCiphertextType);
	// add the objects
	PyModule_AddObject(m, "FieldElement", (PyObject *)&FieldElementType);
	PyModule_AddObject(m, "ECurve", (PyObject *)&ECurveType);
	PyModule_AddObject(m, "ECPoint", (PyObject *)&ECPointType);
	PyModule_AddObject(m, "ECDSASignature", (PyObject *)&ECDSASignatureType);
	PyModule_AddObject(m, "ECDSASignatureScheme", (PyObject *)&ECDSASignatureSchemeType);
	PyModule_AddObject(m, "ECElgamalCiphertext", (PyObject *)&ECElgamalCiphertextType);
	return m;
}
