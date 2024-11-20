# ReZygisk

[English](https://github.com/PerformanC/ReZygisk/blob/main/README.md)|[简体中文](/READMEs/README_zh-CN.md)|[繁體中文](/READMEs/README_zh-TW.md)

ReZygiskはkernelSU、Magisk、APatchにZygiskのAPIサポートを提供するスタンドアローンZygiskであるZygisk Nextのフォークです。

ReZygiskは更に高速かつ効率的なZygisk APIとより寛容なライセンスを、コードベースをC（もともとはC++とRustでした）でアップデート/書き直すことで実現することを目標としています。

> [!NOTE]
> このモジュール/フォークはWIP（Work in Progress、すべての作業が進行中であることを意味します）: ReleasesタブのZipのみを使用するようにしてください。
>
> GitHub [Actions](https://github.com/PerformanC/ReZygisk/actions) よりZipをダウンロードして使用することも可能ですが、デバイスがブートループなどの不具合が起きる可能性があります。ユーザー自身の裁量にて使用してください。

## ReZygiskを使う理由

Zygisk Nextの最新リリースはクローズドソースであり、コードはプロジェクトの開発者のみアクセスできるものです。これはコミュニティがコードに貢献することを妨げるだけではなく、コード監査をも難しくしています。これはZygisk Nextがルート権限で作動するアプリであるため、セキュリティ上深刻な問題です。

Zygisk Nextの開発者はAndroid Communityにて有名かつ信用されています。が、これはコード自体が悪意の無いこと/脆弱でないことを証明するものではありません。

我々（PerformanC）はZygisk Nextの開発者らがコードをクローズドに保つ重要な理由があることは承知していますが、我々はオープンソース/コミュニティドリブンにすることが重要だと考えています。

## メリット

- オープンソース、Free to Use、FOSS (永続的)

## 依存関係

| ツール           | 説明                                    |
|-----------------|----------------------------------------|
| `Android NDK`   | Androidのネイティブ開発環境キット           |

### C++ 依存関係

| 依存        | 説明                          |
|------------|-------------------------------|
| `lsplt`    | シンプルなAndroidのPLTフック     |

## 使い方

ただいま調理中です、しばらくお待ち下さい！（できるだけ早くお届けします）

## インストール

現状、ステーブルリリースはありません。（できるだけ早くお届けします）

## 翻訳

As of now, we don't have integration with another platform for translations but you may contribute to the [add/new-webui](https://github.com/PerformanC/ReZygisk/tree/add/new-webui) branch. Please don't forget to include your GitHub profile in [TRANSLATOR.md](https://github.com/PerformanC/ReZygisk/blob/add/new-webui/TRANSLATOR.md) so that people can see your contribution.

## サポート
For any question related to ReZygisk or other PerformanC projects, feel free to join any of the following channels below:
ReZygisk/他のPerformanCのプロジェクトに対する質問がある場合は以下のリストのどれかから

- Discord Channel: [PerformanC](https://discord.gg/uPveNfTuCJ)
- ReZygisk Telegram Channel: [@rezygiskchat](https://t.me/rezygiskchat)
- PerformanC Telegram Channel: [@performancorg](https://t.me/performancorg)

## Contribution

It is mandatory to follow PerformanC's [Contribution Guidelines](https://github.com/PerformanC/contributing) to contribute to ReZygisk. Following its Security Policy, Code of Conduct, and syntax standard.

## License

ReZygisk is licensed majoritaly under GPL, by Dr-TSNG, but also AGPL 3.0, by The PerformanC Organization, for re-written code. You can read more about it on [Open Source Initiative](https://opensource.org/licenses/AGPL-3.0).
