#include "Clans.h"

#include <string>
#include <vector>

namespace SBF {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-const-variable"
const std::string kClanAnarchLabel = "Anarch";
const std::string kClanAssamiteLabel = "Assamite";
const std::string kClanBaaliLabel = "Baali";
const std::string kClanBrujahLabel = "Brujah";
const std::string kClanCaitiffLabel = "Caitiff";
const std::string kClanCappadocianLabel = "Cappadocian";
const std::string kClanGangrelLabel = "Gangrel";
const std::string kClanGiovanniLabel = "Giovanni";
const std::string kClanInconnuLabel = "Inconnu";
const std::string kClanLasombraLabel = "Lasombra";
const std::string kClanMalkavianLabel = "Malkavian";
const std::string kClanNosferatuLabel = "Nosferatu";
const std::string kClanRavanosLabel = "Ravanos";
const std::string kClanSettiteLabel = "Settite";
const std::string kClanToreadorLabel = "Toreador";
const std::string kClanTremereLabel = "Tremere";
const std::string kClanTzismiceLabel = "Tzismice";
const std::string kClanVentrueLabel = "Ventrue";
const int kClansCount = 18;
const std::string kClanLabels[] = {
    "",
    kClanAnarchLabel,
    kClanAssamiteLabel,
    kClanBaaliLabel,
    kClanBrujahLabel,
    kClanCaitiffLabel,
    kClanCappadocianLabel,
    kClanGangrelLabel,
    kClanGiovanniLabel,
    kClanInconnuLabel,
    kClanLasombraLabel,
    kClanMalkavianLabel,
    kClanNosferatuLabel,
    kClanRavanosLabel,
    kClanSettiteLabel,
    kClanToreadorLabel,
    kClanTremereLabel,
    kClanTzismiceLabel,
    kClanVentrueLabel,
};
#pragma clang diagnostic pop

std::string GetClanLabel(int clan_id) {
  if (clan_id > 0 && clan_id <= kClansCount) {
    return kClanLabels[clan_id];
  }
  return "";
}

void FillClanLabels(std::vector<std::string>& labels) {
  labels.clear();
  for (int id = 1; id <= kClansCount; id++) {
    labels.push_back(GetClanLabel(id));
  }
}
}  // End namespace SBF
