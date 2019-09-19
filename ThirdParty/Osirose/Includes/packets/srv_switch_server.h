#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvSwitchServer : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_SWITCH_SERVER;
        SrvSwitchServer();
        SrvSwitchServer(CRoseReader reader);
        SrvSwitchServer(SrvSwitchServer&&) = default;
        SrvSwitchServer& operator=(SrvSwitchServer&&) = default;
        ~SrvSwitchServer() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSwitchServer& set_port(const uint16_t);
        uint16_t get_port() const;
        SrvSwitchServer& set_sessionId(const uint32_t);
        uint32_t get_sessionId() const;
        SrvSwitchServer& set_sessionSeed(const uint32_t);
        uint32_t get_sessionSeed() const;
        SrvSwitchServer& set_ip(const std::string&);
        const std::string& get_ip() const;
        
        
        static SrvSwitchServer create(const uint16_t& port, const uint32_t& sessionId, const uint32_t& sessionSeed, const std::string& ip);
        static SrvSwitchServer create(const uint8_t* buffer);
        static std::unique_ptr<SrvSwitchServer> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t port;
        uint32_t sessionId;
        uint32_t sessionSeed;
        std::string ip;
};

}
}
