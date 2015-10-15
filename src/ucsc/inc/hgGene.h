/*****************************************************************************
 * Copyright (C) 2000 Jim Kent.  This source code may be freely used         *
 * for personal, academic, and non-profit purposes.  Commercial use          *
 * permitted only by explicit agreement with Jim Kent (jim_kent@pacbell.net) *
 *****************************************************************************/
/* hgGene.h was originally generated by the autoSql program, which also 
 * generated hgGene.c and hgGene.sql.  This header links the database and the RAM 
 * representation of objects. */

struct geneFinder
/* A gene finding program. */
    {
    struct geneFinder *next;  /* Next in singly linked list. */
    unsigned id;	/* Unique ID */
    char *name;	/* Name of gene finder */
    };

void geneFinderStaticLoad(char **row, struct geneFinder *ret);
/* Load a row from geneFinder table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct geneFinder *geneFinderLoad(char **row);
/* Load a geneFinder from row fetched with select * from geneFinder
 * from database.  Dispose of this with geneFinderFree(). */

struct geneFinder *geneFinderCommaIn(char **pS);
/* Create a geneFinder out of a comma separated string. */

void geneFinderFree(struct geneFinder **pEl);
/* Free a single dynamically allocated geneFinder such as created
 * with geneFinderLoad(). */

void geneFinderFreeList(struct geneFinder **pList);
/* Free a list of dynamically allocated geneFinder's */

void geneFinderOutput(struct geneFinder *el, FILE *f, char sep, char lastSep);
/* Print out geneFinder.  Separate fields with sep. Follow last field with lastSep. */

#define geneFinderTabOut(el,f) geneFinderOutput(el,f,'\t','\n');
/* Print out geneFinder as a line in a tab-separated file. */

#define geneFinderCommaOut(el,f) geneFinderOutput(el,f,',',',');
/* Print out geneFinder as a comma separated list including final comma. */

struct hgGene
/* A gene prediction */
    {
    struct hgGene *next;  /* Next in singly linked list. */
    unsigned id;	/* Unique ID */
    char *name;	/* Name of gene */
    unsigned geneFinder;	/* Program that made prediction */
    unsigned startBac;	/* Bac this starts in */
    unsigned startPos;	/* Position within bac where starts */
    unsigned endBac;	/* Bac this ends in */
    unsigned endPos;	/* Position withing bac where ends */
    signed char orientation;	/* Orientation relative to start bac */
    unsigned transcriptCount;	/* Number of transcripts */
    unsigned *transcripts;	/* Array of transcripts */
    };

struct hgGene *hgGeneLoad(char **row);
/* Load a hgGene from row fetched with select * from hgGene
 * from database.  Dispose of this with hgGeneFree(). */

struct hgGene *hgGeneCommaIn(char **pS);
/* Create a hgGene out of a comma separated string. */

void hgGeneFree(struct hgGene **pEl);
/* Free a single dynamically allocated hgGene such as created
 * with hgGeneLoad(). */

void hgGeneFreeList(struct hgGene **pList);
/* Free a list of dynamically allocated hgGene's */

void hgGeneOutput(struct hgGene *el, FILE *f, char sep, char lastSep);
/* Print out hgGene.  Separate fields with sep. Follow last field with lastSep. */

#define hgGeneTabOut(el,f) hgGeneOutput(el,f,'\t','\n');
/* Print out hgGene as a line in a tab-separated file. */

#define hgGeneCommaOut(el,f) hgGeneOutput(el,f,',',',');
/* Print out hgGene as a comma separated list including final comma. */

struct hgTranscript
/* A transcript prediction */
    {
    struct hgTranscript *next;  /* Next in singly linked list. */
    unsigned id;	/* Unique ID */
    char *name;	/* Name of transcript */
    unsigned hgGene;	/* Gene this is in */
    unsigned startBac;	/* Bac this starts in */
    unsigned startPos;	/* Position within bac where starts */
    unsigned endBac;	/* Bac this ends in */
    unsigned endPos;	/* Position withing bac where ends */
    unsigned cdsStartBac;	/* Start of coding region. */
    unsigned cdsStartPos;	/* Start of coding region. */
    unsigned cdsEndBac;	/* End of coding region. */
    unsigned cdsEndPos;	/* End of coding region. */
    signed char orientation;	/* Orientation relative to start bac */
    unsigned exonCount;	/* Number of exons */
    unsigned *exonStartBacs;	/* Exon start positions */
    unsigned *exonStartPos;	/* Exon start positions */
    unsigned *exonEndBacs;	/* Exon start positions */
    unsigned *exonEndPos;	/* Exon start positions */
    };

struct hgTranscript *hgTranscriptLoad(char **row);
/* Load a hgTranscript from row fetched with select * from hgTranscript
 * from database.  Dispose of this with hgTranscriptFree(). */

struct hgTranscript *hgTranscriptCommaIn(char **pS);
/* Create a hgTranscript out of a comma separated string. */

void hgTranscriptFree(struct hgTranscript **pEl);
/* Free a single dynamically allocated hgTranscript such as created
 * with hgTranscriptLoad(). */

void hgTranscriptFreeList(struct hgTranscript **pList);
/* Free a list of dynamically allocated hgTranscript's */

void hgTranscriptOutput(struct hgTranscript *el, FILE *f, char sep, char lastSep);
/* Print out hgTranscript.  Separate fields with sep. Follow last field with lastSep. */

#define hgTranscriptTabOut(el,f) hgTranscriptOutput(el,f,'\t','\n');
/* Print out hgTranscript as a line in a tab-separated file. */

#define hgTranscriptCommaOut(el,f) hgTranscriptOutput(el,f,',',',');
/* Print out hgTranscript as a comma separated list including final comma. */
