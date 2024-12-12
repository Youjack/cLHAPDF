module LHAPDF

export getPDFSet, get_entry
export mkPDF, alphasQ2, xfxQ2

function getPDFSet(setname::AbstractString)::Ptr{Cvoid}
    pdfset = @ccall "libclhapdf".getPDFSet(setname::Cstring)::Ptr{Cvoid}
    return pdfset
end

function get_entry(pdfset::Ptr{Cvoid}, key::AbstractString)::AbstractString
    val = @ccall "libclhapdf".get_entry(pdfset::Ptr{Cvoid}, key::Cstring)::Cstring
    return unsafe_string(val)
end

function mkPDF(setname_nmem::AbstractString)::Ptr{Cvoid}
    pdf = @ccall "libclhapdf".mkPDF(setname_nmem::Cstring)::Ptr{Cvoid}
    atexit(() -> @ccall "libclhapdf".rmPDF(pdf::Ptr{Cvoid})::Cvoid)
    return pdf
end

function alphasQ2(pdf::Ptr{Cvoid}, Q2::Real)::Real
    @ccall "libclhapdf".alphasQ2(pdf::Ptr{Cvoid}, Q2::Float64)::Float64
end
function xfxQ2(pdf::Ptr{Cvoid}, pid::Integer, x::Real, Q2::Real)::Real
    @ccall "libclhapdf".xfxQ2(pdf::Ptr{Cvoid}, pid::Int, x::Float64, Q2::Float64)::Float64
end

end # module
