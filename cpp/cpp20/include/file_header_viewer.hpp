#ifndef FILE_HEADER_VIEWER_HPP
#define FILE_HEADER_VIEWER_HPP

#include "file_reader.hpp"
#include <cstddef>
#include <filesystem>
#include <span>

class FileHeaderViewer
{
public:
  static constexpr size_t DEFAULT_BYTES = 16;
  static constexpr size_t MAX_BYTES = 1024;
  static constexpr size_t BYTES_PER_LINE = 16;

  static_assert(DEFAULT_BYTES <= MAX_BYTES, "DEFAULT_BYTES must not exceed MAX_BYTES");
  static_assert(BYTES_PER_LINE > 0, "BYTES_PER_LINE must be positive");
  static_assert(BYTES_PER_LINE <= MAX_BYTES, "BYTES_PER_LINE must not exceed MAX_BYTES");

  static FileHeaderViewer create(size_t numBytes = DEFAULT_BYTES);
  [[nodiscard]] bool displayFileHeader(const std::filesystem::path &filePath) const;

  FileHeaderViewer() = delete;
  FileHeaderViewer(const FileHeaderViewer &) = delete;
  FileHeaderViewer &operator=(const FileHeaderViewer &) = delete;
  FileHeaderViewer(FileHeaderViewer &&) = delete;
  FileHeaderViewer &operator=(FileHeaderViewer &&) = delete;

private:
  explicit FileHeaderViewer(size_t numBytes);

  void displayFileInfo(const std::filesystem::path &filePath, size_t bytesRead) const;
  void displayCombinedView(std::span<const std::byte> buffer) const;
  void displayOffset(size_t offset) const;
  void displayHexLine(std::span<const std::byte> chunk) const;
  void displayAsciiLine(std::span<const std::byte> chunk) const;
  static constexpr bool isAsciiPrintable(std::byte b);

  size_t m_numBytes;
};

#endif // FILE_HEADER_VIEWER_HPP
