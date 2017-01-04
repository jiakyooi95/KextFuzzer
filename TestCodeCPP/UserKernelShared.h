#if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_4
#define SimpleDriverClassName       com_apple_dts_driver_SimpleDriver_10_4
#else
#define SimpleDriverClassName       com_apple_dts_driver_SimpleDriver
#endif

#define kSimpleDriverClassName      "com_apple_dts_driver_SimpleDriver"
#define kSimpleDriverClassName_10_4 "com_apple_dts_driver_SimpleDriver_10_4"

// Data structure passed between the tool and the user client. This structure and its fields need to have
// the same size and alignment between the user client, 32-bit processes, and 64-bit processes.
// To avoid invisible compiler padding, align fields on 64-bit boundaries when possible
// and make the whole structure's size a multiple of 64 bits.

typedef struct MySampleStruct {
    uint64_t field1;
    uint64_t field2;
} MySampleStruct;


// User client method dispatch selectors.
enum {
    kMyUserClientOpen,
    kMyUserClientClose,
    kMyScalarIStructIMethod,
    kMyScalarIStructOMethod,
    kMyScalarIScalarOMethod,
    kMyStructIStructOMethod,
    kNumberOfMethods // Must be last
};
