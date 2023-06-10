#include <python3.10/Python.h>
#include <stdio.h>

int findPrimes(int num1, int num2) {
  printf("The Prime Numbers in (%d,%d) are:\n", num1, num2);

  for (int i = num1 + 1; i < num2; ++i) {
    int isPrime = 1;

    for (int j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime == 1) {
      printf("%d\n", i);
    }
  }

  return 0;
}

static PyObject *findPrimesWrapper(PyObject *self, PyObject *args) {
  int num1, num2;

  if (!PyArg_ParseTuple(args, "ii", &num1, &num2)) {
    return NULL;
  }

  findPrimes(num1, num2);

  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject *version(PyObject *self) {
  return Py_BuildValue("s", "Version 0.01");
}

static PyMethodDef ExampleMethods[] = {
    {"findPrimes", findPrimesWrapper, METH_VARARGS, "Deneme"},
    {"version", version, METH_NOARGS, "version"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef ExampleModule = {
    PyModuleDef_HEAD_INIT, "Example", "findPrimes Module", -1, ExampleMethods};

PyMODINIT_FUNC PyInit_Example(void) { return PyModule_Create(&ExampleModule); }

