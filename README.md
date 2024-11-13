# Smart Room Monitoring System

**Smart Room Monitoring System** adalah sistem pemantauan cerdas untuk ruangan yang dirancang untuk memantau suhu, kualitas udara, dan tingkat cahaya di dalam ruangan. Sistem ini menggunakan sensor-sensor yang terhubung dengan Arduino UNO, di mana hasil pembacaan sensor ditampilkan pada layar LCD 20x4 I2C dan memberikan peringatan melalui buzzer dan LED jika nilai parameter melebihi batas ambang yang ditentukan.

### Fitur Utama:
1. **Pemantauan Suhu**: Menggunakan sensor DHT22 untuk mengukur suhu ruangan. Jika suhu melebihi ambang batas yang ditentukan (misalnya 30°C), LCD akan menampilkan peringatan suhu tinggi.
2. **Deteksi Kualitas Udara**: Menggunakan sensor MQ-2 untuk mendeteksi adanya asap atau gas berbahaya di ruangan. Jika terdeteksi asap dalam jumlah tinggi, buzzer akan berbunyi sebagai peringatan.
3. **Pemantauan Cahaya**: Menggunakan sensor LDR untuk mendeteksi tingkat cahaya di dalam ruangan. Jika cahaya rendah, LED akan menyala untuk memberikan penerangan tambahan.
4. **Antarmuka LCD 20x4**: Menampilkan data suhu, kelembapan, dan status deteksi (asap/cahaya) secara real-time.

### Komponen yang Digunakan:
- **Arduino UNO**: Sebagai pengontrol utama sistem.
- **DHT22**: Sensor suhu dan kelembapan.
- **MQ-2**: Sensor asap dan gas.
- **LDR**: Sensor cahaya.
- **LED**: Untuk indikator cahaya.
- **Buzzer**: Untuk peringatan asap.
- **LCD 20x4 I2C**: Untuk menampilkan informasi status suhu, kelembapan, dan kualitas udara.

### Cara Kerja:
1. **Suhu dan Kelembapan**: Sistem membaca suhu dan kelembapan dari sensor DHT22. Jika suhu melebihi batas yang ditentukan (misalnya 30°C), LCD akan menampilkan peringatan suhu tinggi.
2. **Kualitas Udara**: Sensor MQ-2 membaca konsentrasi asap atau gas berbahaya. Jika nilai deteksi melebihi ambang batas, buzzer akan berbunyi sebagai peringatan.
3. **Cahaya**: Sensor LDR membaca tingkat cahaya. Jika cahaya di dalam ruangan kurang dari ambang batas, LED akan menyala sebagai penerangan tambahan.

### Diagram Sistem:
![Diagram Sistem](https://github.com/Alizaaaja4/Smart-Room-Monitoring-System/blob/main/dokumentasi2.jpg)

### Instalasi:
1. Pastikan Arduino IDE sudah terinstal di komputer Anda.
2. Pasang semua komponen sesuai dengan skema yang diberikan.
3. Hubungkan Arduino UNO dengan komputer dan upload kode melalui Arduino IDE.
4. Periksa hasil pada LCD dan pastikan semua sensor bekerja dengan baik.

### Referensi:
- [DHT22 Documentation](https://www.adafruit.com/product/385)
- [MQ-2 Sensor](https://www.wingzero.cc/product/mq-2-smoke-gas-sensor/)
- [LCD 20x4 I2C](https://www.dfrobot.com/product-1115.html)
