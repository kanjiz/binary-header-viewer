#include "file_header_viewer.hpp"
#include "error_logger.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <span>
#include <format>
#include <optional>

FileHeaderViewer FileHeaderViewer::create(size_t numBytes)
{
  if (numBytes == 0 || numBytes > MAX_BYTES)
  {
    return FileHeaderViewer(DEFAULT_BYTES);
  }
  return FileHeaderViewer(numBytes);
}

FileHeaderViewer::FileHeaderViewer(size_t numBytes) : m_numBytes(numBytes) {}

bool FileHeaderViewer::displayFileHeader(const std::filesystem::path &filePath) const
{
  auto buffer = FileReader::readFile(filePath, m_numBytes);
  if (!buffer)
  {
    return false;
  }
  displayFileInfo(filePath, buffer->size());
  displayCombinedView(*buffer);
  return true;
}

void FileHeaderViewer::displayFileInfo(const std::filesystem::path &filePath, size_t bytesRead) const
{
  std::cout << std::format("ファイル: {}\n", filePath.string());
  std::cout << std::format("ファイルの最初の {} バイト:\n\n", bytesRead);
}

void FileHeaderViewer::displayCombinedView(std::span<const std::byte> buffer) const
{
  for (size_t offset = 0; offset < buffer.size(); offset += BYTES_PER_LINE)
  {
    auto chunk = buffer.subspan(offset, std::min(BYTES_PER_LINE, buffer.size() - offset));
    displayOffset(offset);
    displayHexLine(chunk);
    displayAsciiLine(chunk);
    std::cout << '\n';
  }
}

void FileHeaderViewer::displayOffset(size_t offset) const
{
  std::cout << std::format("{:08x}: ", offset);
}

void FileHeaderViewer::displayHexLine(std::span<const std::byte> chunk) const
{
  for (const auto &byte : chunk)
  {
    std::cout << std::format("{:02x} ", std::to_integer<int>(byte));
  }
  std::cout << std::string((BYTES_PER_LINE - chunk.size()) * 3, ' ') << " ";
}

void FileHeaderViewer::displayAsciiLine(std::span<const std::byte> chunk) const
{
  std::cout << '|';
  for (const auto &byte : chunk)
  {
    char c = std::to_integer<char>(byte);
    std::cout << (isAsciiPrintable(byte) ? c : '.');
  }
  std::cout << std::string(BYTES_PER_LINE - chunk.size(), ' ') << '|';
}

constexpr bool FileHeaderViewer::isAsciiPrintable(std::byte b)
{
  return std::to_integer<char>(b) >= 32 && std::to_integer<char>(b) <= 126;
}
