#ifndef CLHAPDF_H
#define CLHAPDF_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cPDF cPDF;
cPDF* mkPDF(const char* setname);
void rmPDF(cPDF* cpdf);

double alphasQ2(cPDF* cpdf, double Q2);
double xfxQ2(cPDF* cpdf, int pid, double x, double Q2);

#ifdef __cplusplus
}
#endif

#endif  // CLHAPDF_H
