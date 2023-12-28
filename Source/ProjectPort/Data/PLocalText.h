// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace PLocalText
{
    const FText CommonAlert = NSLOCTEXT("Common", "Alert", "Alert");

    const FText CommonLevel = NSLOCTEXT("Common", "Level", "LV.{0}");

    const FText CommonContentCharacterStat[4] = {
        NSLOCTEXT("ContentCharacterStat", "STR", "STR"),
        NSLOCTEXT("ContentCharacterStat", "DEX", "DEX"),
        NSLOCTEXT("ContentCharacterStat", "INT", "INT"),
        NSLOCTEXT("ContentCharacterStat", "MND", "MND"),
    };

    const FText ManageResetSuccess = NSLOCTEXT("Manage", "ResetSuccess", "Reset Success!");

    const FText ManageEmployRemainPoint = NSLOCTEXT("ManageEmploy", "RemainPoint", "Remain Point : {0}");
    const FText ManageEmployNeedClearPoint = NSLOCTEXT("ManageEmploy", "NeedClearPoint", "Need to make Remain point to 0!");
    const FText ManageEmployNoName = NSLOCTEXT("ManageEmploy", "NoName", "Need to set a Name!");
    const FText ManageEmploySuccess = NSLOCTEXT("ManageEmploy", "Success", "Employ Success!");
    const FText ManageEmployAlreadyEmployment = NSLOCTEXT("ManageEmploy", "AlreadyEmployment", "Already has character name and job!");

    const FText ManageInfoRetireConfirm = NSLOCTEXT("ManageInfo", "RetireConfirm", "Are you sure to Retire character and Remove from list?");
    const FText ManageInfoRetireSuccess = NSLOCTEXT("ManageInfo", "RetireSuccess", "Retirement Success...");
    const FText ManageInfoTrainSuccess = NSLOCTEXT("ManageInfo", "TrainSuccess", "{0} Train Success! +{1}");
}
