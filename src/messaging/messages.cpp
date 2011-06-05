#include "messaging/messages.hpp"


namespace mesos { namespace internal {

boost::unordered_map<std::string, MSGID> MesosProcess::ids;
boost::unordered_map<MSGID, std::string> MesosProcess::names;


static struct Initialization
{
  Initialization()
  {
    MesosProcess::ids[EXIT] = PROCESS_EXIT;
    MesosProcess::names[PROCESS_EXIT] = EXIT;

    MesosProcess::ids[TIMEOUT] = PROCESS_TIMEOUT;
    MesosProcess::names[PROCESS_TIMEOUT] = TIMEOUT;

    MesosProcess::ids[TERMINATE] = PROCESS_TERMINATE;
    MesosProcess::names[PROCESS_TERMINATE] = TERMINATE;
  }
} __initialization__;


struct InitializeMessage
{
  InitializeMessage(const std::string& name, MSGID id)
  {
    MesosProcess::ids[name] = id;
    MesosProcess::names[id] = name;
  }
};


#define INITIALIZE_MESSAGE(ID)               \
    static InitializeMessage __ ## ID(#ID, ID)


INITIALIZE_MESSAGE(F2M_REGISTER_FRAMEWORK);
INITIALIZE_MESSAGE(F2M_REREGISTER_FRAMEWORK);
INITIALIZE_MESSAGE(F2M_UNREGISTER_FRAMEWORK);
INITIALIZE_MESSAGE(F2M_RESOURCE_OFFER_REPLY);
INITIALIZE_MESSAGE(F2M_REVIVE_OFFERS);
INITIALIZE_MESSAGE(F2M_KILL_TASK);
INITIALIZE_MESSAGE(F2M_FRAMEWORK_MESSAGE);
INITIALIZE_MESSAGE(F2M_STATUS_UPDATE_ACK);

INITIALIZE_MESSAGE(M2F_REGISTER_REPLY);
INITIALIZE_MESSAGE(M2F_RESOURCE_OFFER);
INITIALIZE_MESSAGE(M2F_RESCIND_OFFER);
INITIALIZE_MESSAGE(M2F_STATUS_UPDATE);
INITIALIZE_MESSAGE(M2F_LOST_SLAVE);
INITIALIZE_MESSAGE(M2F_FRAMEWORK_MESSAGE);
INITIALIZE_MESSAGE(M2F_ERROR);

INITIALIZE_MESSAGE(S2M_REGISTER_SLAVE);
INITIALIZE_MESSAGE(S2M_REREGISTER_SLAVE);
INITIALIZE_MESSAGE(S2M_UNREGISTER_SLAVE);
INITIALIZE_MESSAGE(S2M_STATUS_UPDATE);
INITIALIZE_MESSAGE(S2M_FRAMEWORK_MESSAGE);
INITIALIZE_MESSAGE(S2M_EXITED_EXECUTOR);

INITIALIZE_MESSAGE(SH2M_HEARTBEAT);
  
INITIALIZE_MESSAGE(M2S_REGISTER_REPLY);
INITIALIZE_MESSAGE(M2S_REREGISTER_REPLY);
INITIALIZE_MESSAGE(M2S_RUN_TASK);
INITIALIZE_MESSAGE(M2S_KILL_TASK);
INITIALIZE_MESSAGE(M2S_KILL_FRAMEWORK);
INITIALIZE_MESSAGE(M2S_FRAMEWORK_MESSAGE);
INITIALIZE_MESSAGE(M2S_UPDATE_FRAMEWORK);
INITIALIZE_MESSAGE(M2S_STATUS_UPDATE_ACK);

INITIALIZE_MESSAGE(E2S_REGISTER_EXECUTOR);
INITIALIZE_MESSAGE(E2S_STATUS_UPDATE);
INITIALIZE_MESSAGE(E2S_FRAMEWORK_MESSAGE);

INITIALIZE_MESSAGE(S2E_REGISTER_REPLY);
INITIALIZE_MESSAGE(S2E_RUN_TASK);
INITIALIZE_MESSAGE(S2E_KILL_TASK);
INITIALIZE_MESSAGE(S2E_FRAMEWORK_MESSAGE);
INITIALIZE_MESSAGE(S2E_KILL_EXECUTOR);

#ifdef __sun__
INITIALIZE_MESSAGE(PD2S_REGISTER_PROJD);
INITIALIZE_MESSAGE(PD2S_PROJD_READY);
INITIALIZE_MESSAGE(S2PD_UPDATE_RESOURCES);
INITIALIZE_MESSAGE(S2PD_KILL_ALL);
#endif // __sun__

INITIALIZE_MESSAGE(GOT_MASTER_TOKEN);
INITIALIZE_MESSAGE(NEW_MASTER_DETECTED);
INITIALIZE_MESSAGE(NO_MASTER_DETECTED);
INITIALIZE_MESSAGE(MASTER_DETECTION_FAILURE);

INITIALIZE_MESSAGE(MESOS_MSGID);

}} // namespace mesos { namespace internal {
