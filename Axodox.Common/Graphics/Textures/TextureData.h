#pragma once
#include "pch.h"
#include "Collections/AlignedAllocator.h"

namespace Axodox::Graphics
{
  enum class TextureImageFormat
  {
    Unknown,
    Rgba8,
    Gray8
  };

  struct TextureData
  {
    uint32_t Width, Height, Stride;
    DXGI_FORMAT Format;
    Collections::aligned_vector<uint8_t> Buffer;

    TextureData();
    TextureData(uint32_t width, uint32_t height, uint32_t stride, DXGI_FORMAT format, Collections::aligned_vector<uint8_t>&& buffer);
    TextureData(uint32_t width, uint32_t height, DXGI_FORMAT format);

    explicit TextureData(const TextureData&) = default;

    TextureData(TextureData&&) noexcept;
    TextureData& operator=(TextureData&&) noexcept;

    uint32_t MainDimension() const;
    uint32_t PixelCount() const;
    uint32_t ByteCount() const;
    bool IsValid() const;

    explicit operator bool() const;

    static TextureData FromBuffer(std::span<const uint8_t> buffer, TextureImageFormat format = TextureImageFormat::Rgba8, std::string* metadata = nullptr);
    std::vector<uint8_t> ToBuffer(std::string_view metadata = "") const;
    
    static TextureData FromWicBitmap(const winrt::com_ptr<IWICBitmap>& wicBitmap);
    winrt::com_ptr<IWICBitmap> ToWicBitmap() const;

    TextureData Resize(uint32_t width, uint32_t height) const;

    winrt::Windows::Graphics::Imaging::SoftwareBitmap ToSoftwareBitmap() const;

    template<typename T>
    T* Row(uint32_t row)
    {
      return reinterpret_cast<T*>(Buffer.data() + row * Stride);
    }

    template<typename T>
    const T* Row(uint32_t row) const
    {
      return reinterpret_cast<const T*>(Buffer.data() + row * Stride);
    }

    template<typename T>
    std::span<T> Cast()
    {
      if (Stride != Width * sizeof(T)) throw std::bad_cast();
      return std::span{ reinterpret_cast<T*>(Buffer.data()), Buffer.size() / sizeof(T) };
    }
  };
}