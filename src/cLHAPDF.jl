module cLHAPDF

export getPDFSet, get_entry
export mkPDF, alphasQ2, xfxQ2

using Libdl: DL_LOAD_PATH
function __init__()
    push!(DL_LOAD_PATH, joinpath(@__DIR__, "..", "lib"))
end

function check_null_pointer(ptr::Ptr{Cvoid})
    if ptr == C_NULL
        throw(ArgumentError("null pointer encountered"))
    end
end

function getPDFSet(setname::AbstractString)::Ptr{Cvoid}
    pdfset = @ccall "libclhapdf".getPDFSet(setname::Cstring)::Ptr{Cvoid}
    return pdfset
end

function get_entry(pdfset::Ptr{Cvoid}, key::AbstractString)::String
    check_null_pointer(pdfset)
    val = @ccall "libclhapdf".get_entry(pdfset::Ptr{Cvoid}, key::Cstring)::Cstring
    return unsafe_string(val)
end

function mkPDF(setname_nmem::AbstractString)::Ptr{Cvoid}
    pdf = @ccall "libclhapdf".mkPDF(setname_nmem::Cstring)::Ptr{Cvoid}
    atexit(() -> @ccall "libclhapdf".rmPDF(pdf::Ptr{Cvoid})::Cvoid)
    return pdf
end

function alphasQ2(pdf::Ptr{Cvoid}, Q2::Real):: Float64
    check_null_pointer(pdf)
    @ccall "libclhapdf".alphasQ2(pdf::Ptr{Cvoid}, Q2::Cdouble)::Cdouble
end
function xfxQ2(pdf::Ptr{Cvoid}, pid::Integer, x::Real, Q2::Real):: Float64
    check_null_pointer(pdf)
    @ccall "libclhapdf".xfxQ2(pdf::Ptr{Cvoid}, pid::Int, x::Cdouble, Q2::Cdouble)::Cdouble
end

end # module
