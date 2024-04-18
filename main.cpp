#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LE2B_12_サクライショウセイ_タイトル";

struct Vector2 {
	float x, y;
};

struct Vector3 {
	float x, y, z;
};

//
Vector3 Add(const Vector3& v1, const Vector3& v2);//加算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);//減算
Vector3 Multiply(float scalar, const Vector3& v);//スカラー倍
float Dot(const Vector3& v1, const Vector3& v2);//内積
float Length(const Vector3& v);//長さ(ノルム)
Vector3 Normalize(const Vector3& v);//正規化

static const int kRowHeight = 20;
static const int kcolumnWidth = 60;

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kcolumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kcolumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kcolumnWidth * 3, y, "%s", label);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	Vector3 v1{ 1.0f, 3.0f, -5.0f };
	Vector3 v2{ 4.0f, -1.0f, 2.0f };
	float k = { 4.0f };

	Vector3 resultAdd = Add(v1, v2);
	Vector3 resultSubtract = Subtract(v1, v2);
	Vector3 resultMultiply = Multiply(k, v1);
	float resultDot = Dot(v1, v2);
	float resultLength = Length(v1);
	Vector3 resultNormalize = Normalize(v2);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		VectorScreenPrintf(0, 0, resultAdd, "  : Add");
		VectorScreenPrintf(0, kRowHeight, resultSubtract, "  : Subtract");
		VectorScreenPrintf(0, kRowHeight * 2, resultMultiply, "  : Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f  : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f  : Length", resultLength);
		VectorScreenPrintf(0, kRowHeight * 5, resultNormalize, "  : Normalize");

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

Vector3 Add(const Vector3& v1, const Vector3& v2)
{
	Vector3 a;
	a.x = v1.x + v2.x;
	a.y = v1.y + v2.y;
	a.z = v1.z + v2.z;
	return a;
}

Vector3 Subtract(const Vector3& v1, const Vector3& v2)
{
	Vector3 a;
	a.x = v1.x - v2.x;
	a.y = v1.y - v2.y;
	a.z = v1.z - v2.z;
	return a;
}

Vector3 Multiply(float scalar, const Vector3& v)
{
	Vector3 a;
	a.x = scalar * v.x;
	a.y = scalar * v.y;
	a.z = scalar * v.z;
	return a;
}

float Dot(const Vector3& v1, const Vector3& v2)
{
	float b;
	b = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return b;
}

float Length(const Vector3& v)
{
	float b;
	b = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return b;
}

Vector3 Normalize(const Vector3& v)
{
	Vector3 a;
	float b;
	b = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	a.x = v.x / b;
	a.y = v.y / b;
	a.z = v.z / b;
	return a;
}
