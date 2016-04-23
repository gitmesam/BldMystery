#ifndef NETBLADE_INT_H

#define NETBLADE_INT_H

#include <dplobby.h>
#include <bld_system.h>
#include <bld_abstract_net.h>
#define BUILD_LIB
#include <export.h>


extern bool is_net_game;
extern LPDIRECTPLAYLOBBY3A gbl_dp_lobby;
extern LPDIRECTPLAY4A gbl_dp_interface;
extern bool is_valid_ipx;
extern bool is_valid_tcp;
extern bld_abstract_net *gbl_net;


extern bool bld_is_net_game(void);

extern bool bld_start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
);
extern HRESULT bld_create_dp_interface(
        LPGUID dp_provider, LPDIRECTPLAY4A *dp_interface
);
extern HRESULT bld_destroy_dp_interface(LPDIRECTPLAY4A dp_interface);
extern bool bld_check_protocol(bool tcp);


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP bld_abstract_net *GetNetInterface(void *cb, void *module);
LIB_EXP void CloseConnection(void);

#ifdef __cplusplus
}
#endif


class bld_net : public bld_abstract_net
{
private:
        void *cb;
public:
        bld_net(void *cb) {
                this->cb = cb;
        }
        virtual void unknown000();
        virtual void unknown004();
        virtual bool is_net_game();
        virtual bool is_server();
        virtual void unknown010();
        virtual void unknown014();
        virtual void unknown018();
        virtual bool start_server(
                const char *game_name, const char *player_name, int max_players,
                bool TCP
        );
        virtual bool browse_sessions(const char *ip_address);
        virtual bool get_browse_result(int index, bld_server_info *info);
        virtual bool join_session(int index, const char *player_name);
        virtual bool is_valid_protocol(bool tcp);
        virtual ~bld_net();
};


#endif /* NETBLADE_INT_H */
