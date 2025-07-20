#include "LHAPDF/LHAPDF.h"
#include "clhapdf.h"
#include <string>
#include <iostream>
using namespace std;

extern "C" {

cPDFSet* getPDFSet(const char* setname) {
    LHAPDF::PDFSet& pdfset = LHAPDF::getPDFSet(string(setname));
    return reinterpret_cast<cPDFSet*>(&pdfset);
}

const char* get_entry(cPDFSet* cpdfset, const char* key) {
    LHAPDF::PDFSet* pdfset = reinterpret_cast<LHAPDF::PDFSet*>(cpdfset);
    return pdfset->get_entry(string(key)).c_str();
}

cPDF* mkPDF(const char* setname_nmem) {
    LHAPDF::PDF* pdf = LHAPDF::mkPDF(string(setname_nmem));
    return reinterpret_cast<cPDF*>(pdf);
}
void rmPDF(cPDF* cpdf) {
    LHAPDF::PDF* pdf = reinterpret_cast<LHAPDF::PDF*>(cpdf);
    delete pdf;
}

double alphasQ2(cPDF* cpdf, double Q2) {
    LHAPDF::PDF* pdf = reinterpret_cast<LHAPDF::PDF*>(cpdf);
    return pdf->alphasQ2(Q2);
}
double xfxQ2(cPDF* cpdf, int pid, double x, double Q2) {
    LHAPDF::PDF* pdf = reinterpret_cast<LHAPDF::PDF*>(cpdf);
    return pdf->xfxQ2(pid, x, Q2);
}

} // extern "C"
