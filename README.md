# 🎮 so_long - A Simple 2D Game

Bu proje, C dili ve MiniLibX kütüphanesi kullanılarak geliştirilmiş basit bir 2D oyun motorudur. Temel amacı, pencereleri yönetmek, görüntüleri işlemek ve harita tabanlı bir oyun döngüsü (game loop) kurgulamaktır.

---

## Özellikler

- **2D Grafik İşleme:** Dkular kullanarak görsel bir oyun dünyası oluşturma.
- **Harita Doğrulama:** `.ber` uzantılı dosyaların okunması ve haritanın kurallara (çevrili duvarlar, geçerli yol vb.) uygunluğunun kontrolü.
- **Oyun Mantığı:** Karakter hareketi, toplanabilir objeler, hareket sayacı ve bitiş noktası mekanikleri.
- **Olay Yönetimi:** Klavye girişlerinin (ESC ve WASD) ve pencere kapatma işlemlerinin asenkron olarak ele alınması.

---

## Teknik Kazanımlar

Bu projeyi geliştirirken şu grafik programlama ve algoritma konularında deneyim kazandım:
- **Grafik Kütüphanesi Yönetimi:** MiniLibX ile pencere oluşturma, görüntü tamponları (image buffers) ve renk yönetimi.
- **Yol Bulma Algoritması:** Haritadaki tüm toplanabilir objelere ve çıkışa ulaşılıp ulaşılamadığını doğrulamak için **Flood Fill** algoritması kullanımı.
- **Bellek Yönetimi:** Dinamik bellek tahsisi ve oyun kapanırken tüm kaynakların (textures, windows, images) temizlenmesi.
- **Harita Parsing:** Dosya okuma (get_next_line) ve matris yapıları üzerinde veri manipülasyonu.

---

## Kurulum ve Kullanım

1. **Depoyu klonlayın:**
   ```bash
   git clone [https://github.com/AbdullahTahaUstunsoy/so_long.git](https://github.com/AbdullahTahaUstunsoy/so_long.git)
   cd so_long
2. Derleme yapın: Terminalde make komutunu çalıştırarak kaynak dosyalarını derleyin ve so_long yürütülebilir dosyasını oluşturun.
3. Oyunu başlatın: ./so_long [harita_yolu] formatını kullanarak (Örn: ./so_long maps/map.ber) oyunu başlatın.
