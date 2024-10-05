#include "file_header_viewer.hpp"
#include "error_logger.hpp"
#include <iostream>
#include <filesystem>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    ErrorLogger::log(std::format("使用法: {} <ファイルパス> [バイト数]", argv[0]));
    return 1;
  }

  std::filesystem::path filePath = argv[1];
  size_t numBytes = FileHeaderViewer::DEFAULT_BYTES;

  if (argc > 2)
  {
    try
    {
      long long inputBytes = std::stoll(argv[2]);
      if (inputBytes < 0)
      {
        ErrorLogger::log("バイト数は正の値である必要があります。デフォルト値を使用します。");
      }
      else
      {
        numBytes = static_cast<size_t>(inputBytes);
      }
    }
    catch (const std::exception &e)
    {
      ErrorLogger::log(std::format("バイト数の解析エラー: {}。デフォルト値を使用します。", e.what()));
    }
  }

  FileHeaderViewer viewer = FileHeaderViewer::create(numBytes);
  return viewer.displayFileHeader(filePath) ? 0 : 1;
}
