#include "file_reader.hpp"
#include "error_logger.hpp"
#include <fstream>
#include <format>

std::optional<std::vector<std::byte>> FileReader::readFile(const std::filesystem::path &filePath, size_t numBytes)
{
  if (!std::filesystem::exists(filePath))
  {
    ErrorLogger::log(std::format("ファイルが存在しません: {}", filePath.string()));
    return std::nullopt;
  }

  std::ifstream file(filePath, std::ios::binary);
  if (!file)
  {
    ErrorLogger::log(std::format("ファイルを開けません: {}", filePath.string()));
    return std::nullopt;
  }

  std::vector<std::byte> buffer(numBytes);
  file.read(reinterpret_cast<char *>(buffer.data()), static_cast<std::streamsize>(numBytes));

  if (file.bad())
  {
    ErrorLogger::log(std::format("ファイル読み込みエラー: {}", filePath.string()));
    return std::nullopt;
  }

  buffer.resize(file.gcount());
  return buffer;
}
