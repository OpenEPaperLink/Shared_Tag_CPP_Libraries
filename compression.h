#include "uzlib/src/uzlib.h"

class decompress {
   public:
// decompress();
#ifdef ENABLE_OEPLFS
    bool openFromFile(char *filename);
#endif
    bool openFromFlash(uint32_t eepBase, uint32_t cSize);
    uint32_t getBlock(uint32_t address, uint8_t *target, uint32_t len);
    uint8_t readByte(uint32_t address);
    void seek(uint32_t address);

#ifdef ENABLE_OEPLFS
    int getNextCompressedBlockFromFile();
#endif
    int getNextCompressedBlockFromFlash();

    decompress();
    ~decompress();

    bool fromFile = false;
    struct uzlib_uncomp *ctx = nullptr;
    void reset();
   protected:
    void setupContext();
    bool readHeader();
    uint8_t *compBuffer = nullptr;
    // uint8_t *uncompBuffer = nullptr;
    uint32_t decompressedSize = 0;
    uint32_t decompressedPos = 0;
    uint32_t compressedSize = 0;
    uint32_t compressedPos = 0;
    uint8_t* outCache = nullptr;
    uint32_t cacheLen = 0;
    uint32_t cacheStart = 0;
#ifdef ENABLE_OEPLFS
    OEPLFile *file = nullptr;
#endif
    uint32_t eepromBase = 0;
    uint8_t *dictionary = nullptr;
};