#define FUCKING_SHIT unsigned int

struct CNetObject {
  public:
    int index;
    static bool isNetworkAuthority;
    irr::u8 type;
    std::string factoryName;
    std::string configFileName;
    irr::s32 factoryIndex;
    irr::s32 cacheIndex;
    bool pause;
    int nodeltatime;
    bool active;
    bool ticked;
    bool killed;
    bool move;
    bool deltaupdate;
    bool updates;
    bool sendkill;
    bool sendonlyvisible;
    irr::u32 last_received_deltastate;
    FUCKING_SHIT ownerpeer;
    FUCKING_SHIT netflags;
    int sendrate;
    int threshmultiplier;
    irr::core::map<FUCKING_SHIT, FUCKING_SHIT> peerstates;
    FUCKING_SHIT lastcorrectstate;
    irr::core::map<unsigned int, FUCKING_SHIT> correctstates;
    irr::core::map<unsigned int, unsigned int> correctstatesmap;
    irr::u16 networkid;
    static short int generatorid;
    static irr::core::array<FUCKING_SHIT, irr::core::irrAllocator<FUCKING_SHIT> > netobjects;
    static irr::core::array<FUCKING_SHIT, irr::core::irrAllocator<FUCKING_SHIT> > tickobjects;
    static FUCKING_SHIT networkid_table[65530];

    CNetObject(const irr::c8 *);
    ~CNetObject();
    virtual void Send_Delta(FUCKING_SHIT, FUCKING_SHIT, FUCKING_SHIT);
    virtual bool Receive_Delta(FUCKING_SHIT &, FUCKING_SHIT, FUCKING_SHIT, bool &);
    virtual void Send_CreateData(FUCKING_SHIT);
    virtual bool Receive_CreateData(FUCKING_SHIT &, bool);
    virtual void setNetworkID(short int);
    short int getNetworkID(void);
    static FUCKING_SHIT getObjectByNetworkId(short int);
    static FUCKING_SHIT NewNetObject(FUCKING_SHIT &);
    static FUCKING_SHIT DeleteNetObject(FUCKING_SHIT &);
    virtual bool Kill(void);
    virtual bool Load(void);
    virtual void DoTick(void);
    virtual int DoCommand(irr::u8, irr::u16);
    virtual bool shouldSendToPlayer(FUCKING_SHIT, bool);
    virtual void SetPaused(bool);
	void SetFactoryName(const char *);
    FUCKING_SHIT getLastKnownCorrectState(irr::u32, irr::u32 &);
    static void UntickAll(void);
    static void RemoveUnactive(void);
    static void TickUnticked(void);
    static void TickDeltaUpdated(void);
    static void DeltaUpdatedReset(void);
    void GenerateNetworkID(void);
    void RemoveFromNetObjectsList(void);
};
