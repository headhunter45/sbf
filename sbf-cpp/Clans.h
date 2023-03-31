#ifndef CLANS_H__
#define CLANS_H__
#include <string>
#include <vector>

namespace SBF {
    const int kClanAnarch = 1;
    const std::wstring kClanAnarchLabel = L"Anarch";
    const int kClanAssamite = 2;
    const std::wstring kClanAssamiteLabel = L"Assamite";
    const int kClanBaali = 3;
    const std::wstring kClanBaaliLabel = L"Baali";
    const int kClanBrujah = 4;
    const std::wstring kClanBrujahLabel = L"Brujah";
    const int kClanCaitiff = 5;
    const std::wstring kClanCaitiffLabel = L"Caitiff";
    const int kClanCappadocian = 6;
    const std::wstring kClanCappadocianLabel = L"Cappadocian";
    const int kClanGangrel = 7;
    const std::wstring kClanGangrelLabel = L"Gangrel";
    const int kClanGiovanni = 8;
    const std::wstring kClanGiovanniLabel = L"Giovanni";
    const int kClanInconnu = 9;
    const std::wstring kClanInconnuLabel = L"Inconnu";
    const int kClanLasombra = 10;
    const std::wstring kClanLasombraLabel = L"Lasombra";
    const int kClanMalkavian = 11;
    const std::wstring kClanMalkavianLabel = L"Malkavian";
    const int kClanNosferatu = 12;
    const std::wstring kClanNosferatuLabel = L"Nosferatu";
    const int kClanRavanos = 13;
    const std::wstring kClanRavanosLabel = L"Ravanos";
    const int kClanSettite = 14;
    const std::wstring kClanSettiteLabel = L"Settite";
    const int kClanToreador = 15;
    const std::wstring kClanToreadorLabel = L"Toreador";
    const int kClanTremere = 16;
    const std::wstring kClanTremereLabel = L"Tremere";
    const int kClanTzismice = 17;
    const std::wstring kClanTzismiceLabel = L"Tzismice";
    const int kClanVentrue = 18;
    const std::wstring kClanVentrueLabel = L"Ventrue";
    const int kClansCount = 18;
    const std::wstring kClans[] = {
        L"",
        kClanAnarchLabel,
        kClanAssamiteLabel,
        kClanBaaliLabel,
        kClanBrujahLabel,
        kClanCaitiffLabel,
        kClanCappadocianLabel,
        kClanGiovanniLabel,
        kClanInconnuLabel,
        kClanLasombraLabel,
        kClanMalkavianLabel,
        kClanNosferatuLabel,
        kClanRavanosLabel,
        kClanSettiteLabel,
        kClanToreadorLabel,
        kClanTremereLabel,
        kClanVentrueLabel,
    };
    const std::wstring& GetClanLabel(int clanId);
    void FillClanLabels(std::vector<std::wstring> clans);
} // End namespace SBF
#endif // End !defined CLANS_H__
