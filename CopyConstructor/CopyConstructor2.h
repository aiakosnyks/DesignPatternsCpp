/*

class Ogrenci{
public:
  std::string isim;
  int yas;

  // Kopyalama kurucusu (Deep copy)
  Ogrenci(const Ogrenci& ogrenci) {
    isim = ogrenci.isim; // Yeni bellek allocate edip ismi kopyalama
    yas = ogrenci.yas;  // Yeni bellek allocate edip yasý kopyalama
  }

  // Destructor (Bellek temizleme)
  ~Ogrenci() {
    delete[] isim;  // isim için ayrýlan belleði serbest býrakma
  }

  int main() {
      Ogrenci ogrenci1("Ahmet", 25);
      Ogrenci ogrenci2(ogrenci1); // Deep copy

      ogrenci1.isim = "Mehmet";

      std::cout << "ogrenci1.isim: " << ogrenci1.isim << std::endl;  // Mehmet
      std::cout << "ogrenci2.isim: " << ogrenci2.isim << std::endl;  // Ahmet (deðiþmez)

      return 0;
  }
};

*/