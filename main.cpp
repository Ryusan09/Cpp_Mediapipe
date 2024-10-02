//  g++ main.cpp -std=c++11 `pkg-config --cflags --libs opencv4`
#include <iostream>           //入出力関連ヘッダ
#include <opencv2/opencv.hpp> //OpenCV関連ヘッダ

int main(int argc, const char *argv[])
{
    // ①画像ファイルの読み込み
    cv::Mat sourceImage = cv::imread("kadai01-2.png", cv::IMREAD_COLOR);
    if (sourceImage.data == 0)
    { // 画像ファイルが読み込めなかった場合
        printf("File not found\n");
        exit(0);
    }
    printf("Width=%d, Height=%d\n", sourceImage.cols, sourceImage.rows); // 横幅と高さ

    // ②画像格納用インスタンスの生成
    cv::Mat grayImage;                // cv::Mat クラス
    cv::Mat binImage;                 // cv::Mat クラス
    std::vector<cv::Mat> bgrImage(3); // cv::Mat クラスの動的配列(初期要素数3)

    // ③ウィンドウの生成と移動
    cv::namedWindow("Source");
    cv::moveWindow("Source", 0, 0);
    cv::namedWindow("Gray");
    cv::moveWindow("Gray", 400, 0);
    cv::namedWindow("Bin");
    cv::moveWindow("Bin", 400, 150);

    // ④画像処理
    cv::cvtColor(sourceImage, grayImage, cv::COLOR_BGR2GRAY);
    cv::split(sourceImage, bgrImage);
    cv::threshold(grayImage, binImage, 128, 255, cv::THRESH_BINARY); // これが課題1
    // cv::threshold(bgrImage[1], binImage, 1, 255, cv::THRESH_BINARY);   // これが課題２

    // ⑤ウィンドウへの画像の表示
    cv::imshow("Source", sourceImage);
    cv::imshow("Gray", grayImage);
    // cv::imshow("B", bgrImage[0]);
    cv::imshow("Bin", binImage);

    // ⑥キー入力待ち
    cv::waitKey(0);

    // ⑦画像の保存
    cv::imwrite("gray.jpg", grayImage);

    return 0;
}
