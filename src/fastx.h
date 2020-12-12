#ifndef PYFASTX_FASTX_H
#define PYFASTX_FASTX_H
#include "Python.h"
#include "zlib.h"
#include "kseq.h"
#include "stdint.h"

typedef struct {
	PyObject_HEAD

	//fasta or fastq file path and name
	char* file_name;

	//always output uppercase sequence
	uint8_t uppercase;

	//file format fasta or fastq
	uint8_t format;

	//gzip open file handle
	gzFile gzfd;

	//kseqs for reading from fasta/q
	kseq_t* kseqs;

	PyObject* (*func) (kseq_t *);

} pyfastx_Fastx;

extern PyTypeObject pyfastx_FastxType;

#endif