#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvRemoveObject : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_REMOVE_OBJECT;
        SrvRemoveObject();
        SrvRemoveObject(CRoseReader reader);
        SrvRemoveObject(SrvRemoveObject&&) = default;
        SrvRemoveObject& operator=(SrvRemoveObject&&) = default;
        ~SrvRemoveObject() = default;
        
        static constexpr size_t size();
        
        
        
        SrvRemoveObject& set_id(const uint16_t);
        uint16_t get_id() const;
        
        
        static SrvRemoveObject create(const uint16_t& id);
        static SrvRemoveObject create(const uint8_t* buffer);
        static std::unique_ptr<SrvRemoveObject> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
};

}
}
