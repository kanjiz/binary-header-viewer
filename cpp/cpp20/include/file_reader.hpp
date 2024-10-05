#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <filesystem>
#include <vector>
#include <cstddef>
#include <optional>

class FileReader
{
public:
  [[nodiscard]] static std::optional<std::vector<std::byte>> readFile(const std::filesystem::path &filePath, size_t numBytes);
};

#endif // FILE_READER_HPP
