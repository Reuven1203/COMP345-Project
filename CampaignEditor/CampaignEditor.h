/**
 * @author Julian D'Addario
 */

#ifndef COMP345_A1_CAMPAIGNEDITOR_H
#define COMP345_A1_CAMPAIGNEDITOR_H

#include "../Map/map.h"
#include "../Observer/MapObserver/MapObserver.h"
#include "../Director/MapDirector/MapDirector.h"
#include "../Builder/MapBuilder/MapBuilder.h"
#include "../Builder/MapBuilder/DefaultMapBuilder.h"
#include "../Campaign/Campaign.h"
#include <fstream>
#include <iostream>

class CampaignEditor {
public:
    CampaignEditor();
    void run();
    Campaign getCampaign();
private:
    Campaign campaign {};
    std::vector<std::string> mapFiles;
    std::string fileName {};
    void printCampaignDetails();
    int getUserInput();
    void addMap();
    void removeMap();
    void editMap();
    void saveCampaign();
    void save(const std::string& filename);
    void loadCampaign();
};


#endif //COMP345_A1_CAMPAIGNEDITOR_H
