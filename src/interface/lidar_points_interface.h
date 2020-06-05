/******************************************************************************
 * Copyright 2020 RoboSense All rights reserved.
 * Suteng Innovation Technology Co., Ltd. www.robosense.ai

 * This software is provided to you directly by RoboSense and might
 * only be used to access RoboSense LiDAR. Any compilation,
 * modification, exploration, reproduction and redistribution are
 * restricted without RoboSense's prior consent.

 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOSENSE BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#pragma once

#include "interface/lidar_base.h"
#include "utility/yaml_reader.hpp"
#include "msg/rs_msg/lidar_points_msg.h"
#include "msg/rs_msg/lidar_packet_msg.h"
#include "msg/rs_msg/lidar_scan_msg.h"
namespace robosense
{
namespace lidar
{
/**
 * @brief Lidar points message interface
 * @detail 1, Will be inheritted by lidar points ROS message adapter and lidar points Proto message adapter
 *         2, Will be inheritted by driver base which relate to lidar points messages(eg: LidarBase)
 */
class LidarPointsInterface : virtual public LidarBase
{
public:
  LidarPointsInterface() = default;
  virtual ~LidarPointsInterface() = default;

  /**
   * @brief initialize function
   * @param config--yaml node
   */
  virtual void init(const YAML::Node& config) = 0;
  /**
   * @brief start function
   */
  virtual void start() = 0;
  /**
   * @brief stop function
   */
  virtual void stop() = 0;
  /**
   * @brief send function
   * @detail send lidar points message through ROS or Proto
   * @param msg--the Robosense lidar points message
   */
  virtual void send(const LidarPointsMsg& msg)
  {
  }
  /**
   * @brief register receive call back function
   * @detail after registration, the lidar points module can pass lidar points message to other module
   * @param callBack--the function pointer of the call back function
   */
  virtual void regRecvCallback(const std::function<void(const LidarPointsMsg&)> callBack) = 0;
  /**
   * @brief the function to depack the msop packets to get pointcloud
   * @detail will be registered to lidar packet receiver to process msop packets and get pointcloud
   * @param pkt_msg--Robosense LidarScanMsg message
   */
  virtual void processMsopScan(const LidarScanMsg& pkt_msg)
  {
  }
  /**
   * @brief the function to depack the difop packets to get parameters for pointcloud
   * @detail will be registered to lidar packet receiver to process difop packets
   * @param pkt_msg--Robosense LidarPacketMsg message
   */
  virtual void processDifopPackets(const LidarPacketMsg& pkt_msg)
  {
  }
};
}  // namespace lidar
}  // namespace robosense
