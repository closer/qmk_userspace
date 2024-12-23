#include "undef.h"

// 入力モードデフォルト
// KEY_INPUT / CURSOR_MODE / SCROLL_MODE / GAME_MODE
#define MODE_DEFAULT_LEFT GAME_MODE
#define MODE_DEFAULT_RIGHT CURSOR_MODE

// CPI = 400 + spd * 200 / AMP = 16.0 + (double)spd * 3.0
#define SPD_OPTION_MAX    7 // 固定: 最大値
#define SPD_DEFAULT_LEFT  3
#define SPD_DEFAULT_RIGHT 3

// 角度 = angle * 12
#define ANGLE_OPTION_MAX    29 // 固定: 最大値
#define ANGLE_DEFAULT_LEFT  8
#define ANGLE_DEFAULT_RIGHT 7

#define INVERT_LEFT_DEFAULT true            // X軸の反転
#define INVERT_RIGHT_DEFAULT true
#define INVERT_SCROLL_DEFAULT false          // スクロールの反転

// 移動量が小さい時の調節
#define SENSITIVITY_MULTIPLIER 1.1 // 一時的倍率
#define SENSITIVITY_DIVISOR 0.5   // 最終的な感度調整
#define SMOOTHING_FACTOR 0.7 // 前の動きの影響度

// スローモード時カーソル速度
#define CPI_SLOW 300
#define AMP_SLOW 4.0

// オートマウスの設定
#define AUTO_MOUSE_DEFAULT false     // デフォルトのオン/オフ
#define AUTO_MOUSE_DEFAULT_LAYER 7  // 使用レイヤー
#define AUTO_MOUSE_THRESHOLD 80     // オートマウスが反応する移動量
#define AUTO_MOUSE_TIME  750        // レイヤー切り替え時間
#define AUTO_MOUSE_DEBOUNCE 40      // 再度オートマウスさせるまでの時間
#define AUTO_MOUSE_DELAY 750        // 一般ボタン使用時のオートマウスオフ時間

// ジョイスティク用定数
#define NO_JOYSTICK_VAL 100         // JSの有無判定閾値
#define KEY_OFFSET 5                // キー入力閾値
#define TIMEOUT_KEY 50              // キー入力間隔

#define JOYSTICK_OFFSET_MIN_DEFAULT 50 // ジョイスティックの小さい値を無視する範囲 最大200
#define JOYSTICK_OFFSET_MAX_DEFAULT 0 // ジョイスティックの大きい値を無視する範囲 最大200

#define SCROLL_DIVISOR 100.0        // スクロール用数値調整
#define JOYSTICK_DIVISOR 40.0       // ジョイスティック用調整用

// OLED設定
#define OLED_DEFAULT true           // true: レイヤー表示, false: 数値表示
#define INTERRUPT_TIME 600          // OLED割り込み時間

// RGBレイヤーデフォルト
#define RGB_LAYER_DEFAULT true

// 一時的モード変更タップ判定ms
#define TERM_TEMP 100

// 斜め入力防止のデフォルト
#define DPAD_EX_DEFAULT true
