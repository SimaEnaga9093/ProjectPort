# ProjectPort
このrepositoryは、簡単なコンシュマーRPGゲームの構造を想定して、UIアーキテクチャと様々な機能の具現をする為に作られたプロジェクトです。
アニメーション、演出みたいなアートワークを除き、純粋なロジックに集中したプロジェクトです。

# 核心要素
## HUDとPopup、そしてBackアクション
全てのUIはHUDかPopupを基盤にします。画面を満たすHUDと、画面を塞ぐPopupに区分しますが、例外もあります。
このプロジェクトでは、基本的な形の物を想定していますが、幾らでも変える事が出来る仕組みになっています。

‘ProjectPortGameModeBase’ではHUDやPopupを開いたり、閉じたりする機能を管理しています。
開発者が望むUIの名前を使ってその機能を動作させることができるし、言わば‘Back’と呼ぶアクションによって最後に開いている物を探して順番に戻る仕組みを具現しました。
これらUIは、閉じる事を自分が決定してHandleをすることも可能です。このPopupは何かを選ばないと閉じることが出来ない、という状況に使う事が出来ます。

>_参考：ProjectPortGameModeBase.h、PHUDWidget.h、PPopupWidget.h_

## 基盤になるUPUserWidgetを親クラスにしたUPCommon~クラス達
UIを作る上で一番大事だと思う基礎クラス達です。基本的なボタンやタブを具現していますが、Unreal Enigne UMGで構成している色んなモジュールを包み込む形で具現します。
これらを作り理由については、大きく二つのメリットがあります。

1．**UIアーチストが管理する作業を減らす事が出来る。**
協業によって大事なところですが、ゲームに使用するデザインはかなり一貫性を持っていると思います。同じデザインのボタンを何回も作ろうのは効率的ではなく、修正も難しいです。
その為、デザインに使うUIを何種類かに減らし、一括的に管理すろ事が出来ます。

2．**付加機能を付ける事が出来る。**
簡単な例として、ボタン‘だけ’を使う事はあんまり無いです。そこに文字を書いたり、大きさを変えたりします。それらは一度作ったら様々な状況で簡単に使う事が出来ます。
ただし、その機能が本当に何回も上手く活用されるか考えながら作らないとだめです。

>_参考：PCommonButton.h、PCommonTab.h、PCommonPopupWidget.h_

## 一文のお知らせ、ToastMessage
ゲームでは、Popupまでは必要されない簡単な一文のお知らせをよく流します。その時、使うために作った機能です。
具現した構造によって設定された時間の後、画面の操作、もしくはBackアクションによって閉じる事が出来ます。一度に一文しか見せてくれませんが、全ての文章が待機され、連速に流す事も出来仕組みです。

>_参考：ProjectPortGameModeBase.h、PToastMessageWidget.h_

## ローカライズ支援
Unreal Engineが支援するローカライズ機能ですが、規則なしで使ったら管理するのが難しい構造なので、この形に整理し書くことをお勧めしています。
これはただプログラマーだけの為に作った物ではない、協業の為なファイルです。

プログラマー同士では、既に使っている単語や文章がいるかどうか確認する事が出来るし、プランナー達は管理したり、修正したい部分をたやすく探す事が出来ます。

>_参考：PLocalText.h_

# コンテンツ説明
## Quest
色んなクエストを受注するコンテンツです。大きくバトル、アドベンチャー、クラフトに分けてその中で選べたい物を選択する仕組みにしました。

このコンテンツではデータによって作られる流動的なリストを簡単な形でお見せしています。

## Manage
ユーザーが持っているキャラクターを管理するコンテンツです。雇用ボタンを押した後、キャラクターの色んな情報を記入して雇用が進行されます。
キャラクター自体を押したら情報を見せるPopupが発生し、解雇や訓練も行う事が出来ます。

ここではデータの読み書きと、多様な形態の一文のお知らせを見ることが出来ます。

# プレイ動画
[ProjectPortSample](https://github.com/SimaEnaga9093/ProjectPort/blob/main/ProjectPortSample.mp4)

repository最上にあるProjectPortSampleで実際のプレイを録画しました。
