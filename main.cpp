#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <windows.h>

int main() {
  int dummy;
  std::string wantPlay;
  int spead = 400;
  int size = 4;
  std::string useStanderdSetting;
  std::string badapplepath="C:\\Users\\tyk12\\app\\badappleChallengeInConsole\\bin\\Debug\\badapple.mp4";

  SetConsoleOutputCP(CP_UTF8); // 出力を UTF-8 に
  SetConsoleCP(CP_UTF8);       // 入力を UTF-8 に

  std::cout << "再生しますか？ (Y/N): ";
  std::cin >> wantPlay;
  if (wantPlay != "Y" && wantPlay != "y") {
    return 0;
  }

  std::cout << "標準設定を使用しますか？ (Y/N): ";
  std::cin >> useStanderdSetting;
  if (useStanderdSetting == "N" || useStanderdSetting == "n") {
    std::cout << "再生速度を入力してください (例: 録画800,普通400): ";
    std::cin >> spead;

    std::cout << "画素サイズを入力してください (例: 4,8,16): ";
    std::cin >> size;
  }

  // 動画ファイルを開く
  cv::VideoCapture cap(badapplepath);
  if (!cap.isOpened()) { // ファイルが開けなかった場合
    std::cerr << "Error: ファイルが開けませんでした" << std::endl;
    std::cin >> dummy;
    return -1;
  }

  int width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
  int height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
  int totalFrames = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_COUNT));
  int fps = static_cast<int>(cap.get(cv::CAP_PROP_FPS));
  std::string flame;

  std::cout << "動画の幅: " << width << ", 高さ: " << height
            << "トータルフレーム" << totalFrames << std::endl;

  for (int i = 0; i < totalFrames; i++) {
    cv::Mat frame;
    cap >> frame;
    if (frame.empty()) {
      std::cout << "動画の読み込みが完了しました。" << std::endl;
      break;
    }
    for (int j = 0; j < height / size; j++) {
      for (int k = 0; k < width / size; k++) {
        cv::Vec3b color = frame.at<cv::Vec3b>(j * size, k * size);
        int gray = (color[0] + color[1] + color[2]) / 3;
        if (gray > 230) {
          flame.append("■ ");
        } else if (gray < 20) {
          flame.append("□ ");
        } else {
          flame.append("□ ");
        }
      }
      flame.append("\n");
    }
    std::cout << "\x1b[H";
    std::cout << flame;
    flame.clear();
    cv::waitKey(spead / fps);
  }

  std::cin >> dummy;
  return 0;
}