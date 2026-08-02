//added for websocket
#pragma once

#include "pch.h"

//added for websocket
#include "output-config.h"

struct TargetOutputStats {
    uint64_t totalFrames = 0;
    uint64_t droppedFrames = 0;
    uint64_t totalBytes = 0;
    float congestion = 0.0f;
};

class PushWidget : public QWidget {
    Q_OBJECT
public:
    PushWidget(const std::string& targetid, QWidget* parent = 0);
    virtual ~PushWidget() {}
    virtual bool ShowEditDlg() = 0;
    virtual void StartStreaming() = 0;
    virtual void StopStreaming() = 0;
    virtual void OnOBSEvent(obs_frontend_event ev) = 0;
    virtual QPushButton* GetDeleteButton() = 0;

    // Websocket access methods
    virtual QString GetTargetId() const = 0;
    virtual QString GetTargetName() const = 0;
    virtual QString GetStatusText() const = 0;
    virtual bool IsRunning() const = 0;
    virtual TargetOutputStats GetOutputStats() const = 0;
    virtual void UpdateUI() = 0;
    
    // Add this method to access config
    virtual OutputTargetConfigPtr GetConfig() const = 0;
};

PushWidget* createPushWidget(const std::string& targetId, QWidget* parent = 0);
