# ReZygisk

[English](https://github.com/PerformanC/ReZygisk/blob/main/README.md)

ReZygisk adalah turunan dari Zygisk Next, sebuah implementasi mandiri Zygisk, yang mendukung API Zygisk untuk KernelSU, Magisk (selain versi bawaan), dan APatch (dalam tahap pengembangan).

Proyek ini bertujuan untuk memodernisasi dan menulis ulang basis kode ke dalam bahasa pemorgraman C (dari C++ dan Rust), memungkinkan implementasi API Zygisk yang lebih efisien dan cepat dengan lisensi yang lebih permisif.

> [!NOTE]
> [CATATAN]
> 
> Modul/turunan ini sedang dalam tahap pengembangan. gunakan hanya file .zip dari halaman Rilis.
>
> Anda dapat menginstal file .zip dari halaman [Actions](https://github.com/PerformanC/ReZygisk/actions), namun instalan ini sepenuhnya menjadi tanggung jawab Anda karena perangkat dapat mengalami bootloop.

## Mengapa?

Rilisan terbaru dari Zygisk Next tidak bersifat open-source, dengan kode yang sepenuhnya dikendalikan oleh developernya. Hal ini tidak hanya membatasi kemampuan kami untuk berkontribusi pada proyek ini, tetapi juga membuat kode tidak dapat diaudit, yang menjadi masalah utama keamanan karena Zygisk Next adalah modul yang berjalan dengan hak superuser (root), yang memiliki akses ke seluruh sistem.

Meskipun developer Zygisk Next terkenal dan dipercaya dalam komunitas Android, hal ini tidak menjamin bahwa kode tersebut bebas dari bahaya atau kerentanan. Kami (PerformanC) memahami alasan mereka untuk menjaga kode tetap tertutup, tetapi kami memiliki pandangan yang berbeda.

## Kelebihan

- FOSS (Free and Open Source Software) Selamanya.

## Komponen Pendukung

| Alat            | Deskripsi                                |
|-----------------|------------------------------------------|
| `Android NDK`   | Native Development Kit untuk Android     |

### Komponen Pendukung C++

| Komponen   | Deskripsi                       |
|------------|---------------------------------|
| `lsplt`    | Simple PLT Hook untuk Android   |

## Penggunaan

Kami saat ini sedang dalam tahap pengembangan. (Segera Hadir)

## Instalasi

Saat ini belum tersedia rilisan yang stabil. (Segera Hadir)

## Terjemahan

Saat ini, kami belum terintegrasi dengan platform lain untuk penerjemahan, tetapi Anda dapat berkontribusi pada cabang [add/new-webui](https://github.com/PerformanC/ReZygisk/tree/add/new-webui). Jangan lupa untuk menyertakan profil GitHub Anda di [TRANSLATOR.md](https://github.com/PerformanC/ReZygisk/blob/add/new-webui/TRANSLATOR.md) agar orang lain dapat melihat kontribusi Anda.

## Dukungan
Untuk pertanyaan terkait ReZygisk atau proyek PerformanC lainnya, silakan bergabung ke salah satu saluran berikut:

- Saluran Discord: [PerformanC](https://discord.gg/uPveNfTuCJ)
- Saluran Telegram ReZygisk: [@rezygiskchat](https://t.me/rezygiskchat)
- Saluran Telegram PerformanC: [@performancorg](https://t.me/performancorg)

## Kontribusi

Wajib mengikuti [Pedoman Kontribusi](https://github.com/PerformanC/contributing) PerformanC untuk berkontribusi pada ReZygisk. Sesuai dengan Kebijakan Keamanan, Kode Etik, dan standar struktur dan format yang berlaku.

## Lisensi

ReZygisk sebagian besar berlisensi di bawah GPL, oleh Dr-TSNG, tetapi juga AGPL 3.0, oleh The PerformanC Organization, untuk kode yang ditulis ulang. Anda dapat juga membaca lebih lanjut di [Open Source Initiative](https://opensource.org/licenses/AGPL-3.0).
