#include <IOKit/IOService.h>
#include <IOKit/IOUserClient.h>
#include "CustomDriver.h"

#if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_4
#define SimpleUserClientClassName com_apple_dts_driver_SimpleUserClient_10_4
#else
#define SimpleUserClientClassName com_apple_dts_driver_SimpleUserClient
#endif

class SimpleUserClientClassName : public IOUserClient
{
#if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_4
    OSDeclareDefaultStructors(com_apple_dts_driver_SimpleUserClient_10_4)
#else
    OSDeclareDefaultStructors(com_apple_dts_driver_SimpleUserClient)
#endif
    
protected:
    SimpleDriverClassName*                  fProvider;
    task_t                                  fTask;
    bool                                    fCrossEndian;
#if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_4
    static const IOExternalMethod           sMethods[kNumberOfMethods];
#else
    static const IOExternalMethodDispatch   sMethods[kNumberOfMethods];
#endif
    
public:
    // IOUserClient methods
    virtual void stop(IOService* provider);
    virtual bool start(IOService* provider);
    
    virtual bool initWithTask(task_t owningTask, void* securityToken, UInt32 type, OSDictionary* properties);
    
    virtual IOReturn clientClose(void);
    virtual IOReturn clientDied(void);
    
    virtual bool willTerminate(IOService* provider, IOOptionBits options);
    virtual bool didTerminate(IOService* provider, IOOptionBits options, bool* defer);
    
    virtual bool terminate(IOOptionBits options = 0);
    virtual bool finalize(IOOptionBits options);
    
protected:
    
#if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_4
    // Legacy KPI - only supports access from 32-bit user processes.
    virtual IOExternalMethod* getTargetAndMethodForIndex(IOService** targetP, UInt32 index);
#else
    // KPI for supporting access from both 32-bit and 64-bit user processes beginning with Mac OS X 10.5.
    virtual IOReturn externalMethod(uint32_t selector, IOExternalMethodArguments* arguments,
                                    IOExternalMethodDispatch* dispatch, OSObject* target, void* reference);
#endif
    
    // SimpleUserClient methods
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_4
    static IOReturn sOpenUserClient(SimpleUserClientClassName* target, void* reference, IOExternalMethodArguments* arguments);
#endif
    virtual IOReturn openUserClient(void);
    
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_4
    static IOReturn sCloseUserClient(SimpleUserClientClassName* target, void* reference, IOExternalMethodArguments* arguments);
#endif
    virtual IOReturn closeUserClient(void);
    
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_4
    static IOReturn sScalarIStructI(SimpleUserClientClassName* target, void* reference, IOExternalMethodArguments* arguments);
#endif
    virtual IOReturn ScalarIStructI(uint32_t inNumber, MySampleStruct* inStruct, uint32_t inStructSize);
    
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_4
    static IOReturn sScalarIStructO(SimpleUserClientClassName* target, void* reference, IOExternalMethodArguments* arguments);
#endif
    virtual IOReturn ScalarIStructO(uint32_t inNumber1, uint32_t inNumber2, MySampleStruct* outStruct, uint32_t* outStructSize);
    
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_4
    static IOReturn sScalarIScalarO(SimpleDriverClassName* target, void* reference, IOExternalMethodArguments* arguments);
#endif
    
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_4
    static IOReturn sStructIStructO(SimpleUserClientClassName* target, void* reference, IOExternalMethodArguments* arguments);
#endif
    virtual IOReturn StructIStructO(MySampleStruct* inStruct, MySampleStruct* outStruct, uint32_t inStructSize, uint32_t* outStructSize);
};
