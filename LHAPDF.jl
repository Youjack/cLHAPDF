module LHAPDF

export mkPDF, alphasQ2, xfxQ2

function mkPDF(setname::AbstractString)::Ptr{Cvoid}
    pdf = @ccall "libclhapdf".mkPDF(setname::Cstring)::Ptr{Cvoid}
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
