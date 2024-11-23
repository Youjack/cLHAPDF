#include "LHAPDF/LHAPDF.h"
#include "clhapdf.h"
#include <string>
#include <iostream>
using namespace LHAPDF;
using namespace std;

extern "C" {

cPDF* mkPDF(const char* setname) {
    PDF* pdf = mkPDF(string(setname), 0);
    return reinterpret_cast<cPDF*>(pdf);
}
void rmPDF(cPDF* cpdf) {
    PDF* pdf = reinterpret_cast<PDF*>(cpdf);
    delete pdf;
}

double alphasQ2(cPDF* cpdf, double Q2) {
    PDF* pdf = reinterpret_cast<PDF*>(cpdf);
    return pdf->alphasQ2(Q2);
}
double xfxQ2(cPDF* cpdf, int pid, double x, double Q2) {
    PDF* pdf = reinterpret_cast<PDF*>(cpdf);
    return pdf->xfxQ2(pid, x, Q2);
}

} // extern "C"
