#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliAcceptReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_ACCEPT_REQ;
        CliAcceptReq();
        CliAcceptReq(CRoseReader reader);
        CliAcceptReq(CliAcceptReq&&) = default;
        CliAcceptReq& operator=(CliAcceptReq&&) = default;
        ~CliAcceptReq() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliAcceptReq create();
        static CliAcceptReq create(const uint8_t* buffer);
        static std::unique_ptr<CliAcceptReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
