// 
//  Описатели внутренней структуры nvram-файлов
// 

// Хуавеевские типы данных
#define U32 uint32_t 
#define U16 uint16_t
#define U8 uint8_t

#define FILE_MAGIC_NUM 0x224e4944 // Сигнатура заголовка файла

// Струкура заголовка nv-файла
struct nvfile_header {

    U32 magicnum;   // сигнатура
    U32 ctrl_size;  // размер управляющих структур (смещение до данных)
    U16 version;    // * file version * /
    U8 modem_num;   // номер модема для мультимодемных конфигураций
    U8 reserved1;   
    U32 file_offset; // смещение до списка файлов
    U32 file_num;    // число файлов в списке 
    U32 file_size;   // размер списка файлов
    U32 item_offset;  // смещение до списка ячеек
    U32 item_count;   // число ячеек в списке
    U32 item_size;    // размер списка ячеек
    U8 reserve2 [12];
    U32 timetag [4]; // отметка воемени
    U8 product_version [32]; // версия устройства
};

//  Элемент каталога файлов
struct nv_file {
    U32 id; // номер файла
    U8 name [28]; // имя файла
    U32 size; // размер файла
    U32 offset; // смещение до файла
};

// Элемент каталога ячеек
struct nv_item {
    U16 id; // номер ячейки
    U16 len; // размер в байтах
    U32 off; // смещение от начала файла
    U16 file_id; // файл, к которому относится ячейка
    U16 priority; // приоритет ячейки
    U8 modem_num; // номер модема
    U8 reserved [3]; 
};
