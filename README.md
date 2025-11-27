# Bad Apple Challenge in Console

コンソール画面（コマンドプロンプトなど）で Bad Apple の動画を文字（アスキーアート風）で再生する C++ プロジェクトです。

## 必要要件

* C++ コンパイラ (C++17 対応)
* CMake
* OpenCV
* spdlog
* vcpkg (推奨)

## ビルド方法

このプロジェクトは CMake と vcpkg を使用してビルドすることを想定しています。

```bash
# ビルド用ディレクトリの作成
mkdir build
cd build

# CMake の設定 (vcpkg のツールチェーンファイルを指定してください)
# 例: cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake ..

# ビルド
cmake --build .
```

## 実行方法

ビルドが成功すると `bin` ディレクトリなどに実行ファイルが生成されます。
実行ファイルと同じディレクトリ（またはカレントディレクトリ）に `badapple.mp4` を配置して実行してください。

```bash
./badappleChallengeInConsole.exe
```

実行後、以下の設定を聞かれます：
1. 再生しますか？ (Y/N)
2. 標準設定を使用しますか？ (Y/N)
   - Noの場合、再生速度と画素サイズ（解像度）を指定できます。

ちなみにもうすでにあるexeファイルはbuild後のファイルなのでbuildしなくても実行できます。