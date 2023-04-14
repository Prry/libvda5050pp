// Copyright Open Logistics Foundation
// 
// Licensed under the Open Logistics Foundation License 1.3.
// For details on the licensing terms, see the LICENSE file.
// SPDX-License-Identifier: OLFL-1.3
// 
// This file contains the definition for the VD(M)A 5050 AGVPosition
// SEE: Schnittstelle zur Kommunikation zwischen Fahrerlosen Transportfahr-
// zeugen (FTF) und einer Leitsteuerung
// VDA 5050 Version 2.0, Mai 2020

#ifndef INCLUDE_VDA5050PP_MODEL_AGVPOSITION_HPP_
#define INCLUDE_VDA5050PP_MODEL_AGVPOSITION_HPP_

#include <optional>
#include <string>

namespace vda5050pp {
/// Defines the position on a map in world coordinates. Each floor has its own map.
struct AGVPosition {
  /// False: position is not initialized
  /// True: position is initialized
  bool positionInitialized;

  /// Range: [0.0 … 1.0] Describes the quality of the localization and
  /// therefore, can be used e. g. by SLAMAGVs to describe how accurate the
  /// current position information is.
  /// 0.0: position unknown
  /// 1.0: position known
  /// Optional for vehicles that cannot estimate their localizarion score.
  /// Only for logging and visualization purposes.
  std::optional<double> localizationScore;

  /// [m] Value for the deviation range of the position in meters.
  /// Optional for vehicles that cannot estimate their deviation e.g.
  /// grid-based localization.
  /// Only for logging and visualization purposes
  std::optional<double> deviationRange;

  /// [m] X - position on the map in reference to the map coordinate system.
  ///  Precision is up to the specific implementation
  double x;

  /// [m] Y - position on the map in reference to the map coordinate system.
  /// Precision is up to the specific implementation.
  double y;

  /// [rad] Range : [-Pi … Pi] Orientation of the AGV. string mapId
  /// Unique identification of the map in which the position is referenced.
  /// Each map has the same origin of coordinates. When an AGV uses
  /// an elevator, e.g. leading from a departure floor to a target floor and
  /// spawn in the related lift node on the map of the target floor.
  double theta;

  /// Unique identification of the map in which the position is referenced
  std::string mapId;

  /// Additional information on the map.
  std::optional<std::string> mapDescription;

  constexpr bool operator==(const AGVPosition &other) const {
    if (positionInitialized != other.positionInitialized) return false;
    if (localizationScore != other.localizationScore) return false;
    if (deviationRange != other.deviationRange) return false;
    if (x != other.x) return false;
    if (y != other.y) return false;
    if (theta != other.theta) return false;
    return true;
  }
  constexpr bool operator!=(const AGVPosition &other) const { return !this->operator==(other); }
};
}  // namespace vda5050pp
#endif  // INCLUDE_VDA5050PP_MODEL_AGVPOSITION_HPP_
