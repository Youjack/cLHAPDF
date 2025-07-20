#ifndef CLHAPDF_H
#define CLHAPDF_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cPDFSet cPDFSet;
cPDFSet* getPDFSet(const char* setname);

const char* get_entry(cPDFSet* cpdfset, const char* key);

typedef struct cPDF cPDF;
cPDF* mkPDF(const char* setname_nmem);
void rmPDF(cPDF* cpdf);

double alphasQ2(cPDF* cpdf, double Q2);
double xfxQ2(cPDF* cpdf, int pid, double x, double Q2);

#ifdef __cplusplus
}
#endif

#endif  // CLHAPDF_H
