#ifndef __radprofmodule__
#define __radprofmodule__

/*
Header file for RadProfModule.c, which see for information.

History:
2004-10-13 ROwen    modified libnumarray.h include to match numarray 1.1 docs.
2008-10-01 ROwen    radAsymmWeighted: changed bias from long to Float64.
*/

#include "Python.h"
#include "libnumarray.h"

#ifdef __cplusplus
extern "C" {
#endif

// routines visible to Python
static PyObject *Py_radAsymm(PyObject *self, PyObject *args);
static PyObject *Py_radProf(PyObject *obj, PyObject *args);
static PyObject *Py_radIndByRadSq(PyObject *obj, PyObject *args);
static PyObject *Py_radSqByRadInd(PyObject *obj, PyObject *args);
static PyObject *Py_radSqProf(PyObject *obj, PyObject *args);

// internal routines
long g_radProf_setup(
    long rad
);
void g_radProf_free(
    void
);
long g_radAsymm_alloc(
    long nElt
);
void g_radAsymm_free(
    void
);
long radAsymm(
    long inLenI, long inLenJ,
    Float32 data[inLenI][inLenJ],
    Bool mask[inLenI][inLenJ],
    long iCtr, long jCtr,
    long rad,
    Float64 *asymmPtr,
    Float64 *totCountsPtr
);
long radAsymmWeighted(
    long inLenI, long inLenJ,
    Float32 data[inLenI][inLenJ],
    Bool mask[inLenI][inLenJ],
    long iCtr, long jCtr,
    long rad,
    Float64 bias,
    Float64 readNoise,
    Float64 ccdGain,
    Float64 *asymmPtr,
    Float64 *totCountsPtr
);
long radProf(
    long inLenI, long inLenJ,
    Float32 data[inLenI][inLenJ],
    Bool mask[inLenI][inLenJ],
    long iCtr, long jCtr,
    long rad,
    long outLen,
    Float64 *mean,
    Float64 *var,
    Int32 *nPts,
    Float64 *totCountsPtr
);
long radSqProf(
    long inLenI, long inLenJ,
    Float32 data[inLenI][inLenJ],
    Bool mask[inLenI][inLenJ],
    long iCtr, long jCtr,
    long rad,
    long outLen,
    Float64 *mean,
    Float64 *var,
    Int32 *nPts,
    Float64 *totCountsPtr
);

#ifdef __cplusplus
}
#endif

#endif
