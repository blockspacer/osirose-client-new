#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class IscAlive : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::ISC_ALIVE;
        IscAlive();
        IscAlive(CRoseReader reader);
        IscAlive(IscAlive&&) = default;
        IscAlive& operator=(IscAlive&&) = default;
        ~IscAlive() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static IscAlive create();
        static IscAlive create(const uint8_t* buffer);
        static std::unique_ptr<IscAlive> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
