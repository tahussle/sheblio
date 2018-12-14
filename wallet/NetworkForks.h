#ifndef NETWORKFORKS_H
#define NETWORKFORKS_H

#include "init.h"
#include <map>

enum NetworkFork : uint16_t
{
    NETFORK__1_FIRST_ONE = 0,
    NETFORK__2_CONFS_CHANGE,
    NETFORK__3_TACHYON
};

class NetworkForks
{
    std::map<NetworkFork, int> forksToBlockMap;
    std::map<int, NetworkFork> blockToForksMap;
    const int&                 bestHeight_internal;

public:
    NetworkForks(const std::map<NetworkFork, int>& ForksToBlocks, const int& BestHeightVar);

    bool isForkActivated(NetworkFork fork) const;

    NetworkFork getForkAtBlockNumber(int blockNumber) const;

    int getFirstBlockOfFork(NetworkFork fork) const;
};

const NetworkForks
MainnetForks(std::map<NetworkFork, int>{{NetworkFork::NETFORK__1_FIRST_ONE, 0},
                                        // number of stake confirmations changed to 10
                                        {NetworkFork::NETFORK__2_CONFS_CHANGE, 248000},
                                        // unset yet
                                        {NetworkFork::NETFORK__3_TACHYON, 1000000}},
             nBestHeight);

const NetworkForks
TestnetForks(std::map<NetworkFork, int>{{NetworkFork::NETFORK__1_FIRST_ONE, 0},
                                        {NetworkFork::NETFORK__2_CONFS_CHANGE,
                                         std::numeric_limits<decltype(nBestHeight)>::max()},
                                        // Roughly Aug 1 2018 Noon EDT
                                        {NetworkFork::NETFORK__3_TACHYON, 110100}},
             nBestHeight);

const NetworkForks& GetNetForks();

#endif // NETWORKFORKS_H
