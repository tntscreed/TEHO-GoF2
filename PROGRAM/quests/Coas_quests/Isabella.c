void IsabellaSetCurrentState(string _TypeOfCheck)
{
if (_TypeOfCheck == "all" || _TypeOfCheck == "KillFort")
{
DeleteAttribute(pchar, "RomanticQuest.Cheking.KillFort");
pchar.RomanticQuest.State.KillFort = Statistic_AddValue(PChar, "pir_KillFort", 0) +
Statistic_AddValue(PChar, "eng_KillFort", 0) +
Statistic_AddValue(PChar, "fra_KillFort", 0) +
Statistic_AddValue(PChar, "spa_KillFort", 0) +
Statistic_AddValue(PChar, "hol_KillFort", 0);
}
if (_TypeOfCheck == "all" || _TypeOfCheck == "TakeTown")
{
DeleteAttribute(pchar, "RomanticQuest.Cheking.TakeTown");
pchar.RomanticQuest.State.TakeTown = Statistic_AddValue(PChar, "pir_TakeTown", 0) +
Statistic_AddValue(PChar, "eng_TakeTown", 0) +
Statistic_AddValue(PChar, "fra_TakeTown", 0) +
Statistic_AddValue(PChar, "spa_TakeTown", 0) +
Statistic_AddValue(PChar, "hol_TakeTown", 0);
}
if (_TypeOfCheck == "all" || _TypeOfCheck == "GrabbingTown")
{
DeleteAttribute(pchar, "RomanticQuest.Cheking.GrabbingTown");
pchar.RomanticQuest.State.GrabbingTown = Statistic_AddValue(PChar, "pir_GrabbingTown", 0) +
Statistic_AddValue(PChar, "eng_GrabbingTown", 0) +
Statistic_AddValue(PChar, "fra_GrabbingTown", 0) +
Statistic_AddValue(PChar, "spa_GrabbingTown", 0) +
Statistic_AddValue(PChar, "hol_GrabbingTown", 0);
}
if (_TypeOfCheck == "all" || _TypeOfCheck == "AbordShip")
{
DeleteAttribute(pchar, "RomanticQuest.Cheking.AbordShip");
pchar.RomanticQuest.State.AbordShip = Statistic_AddValue(PChar, "pir_AbordShip", 0) +
Statistic_AddValue(PChar, "eng_AbordShip", 0) +
Statistic_AddValue(PChar, "fra_AbordShip", 0) +
Statistic_AddValue(PChar, "spa_AbordShip", 0) +
Statistic_AddValue(PChar, "hol_AbordShip", 0);
}
if (_TypeOfCheck == "all" || _TypeOfCheck == "KillShip")
{
DeleteAttribute(pchar, "RomanticQuest.Cheking.KillShip");
pchar.RomanticQuest.State.KillShip = Statistic_AddValue(PChar, "pir_KillShip", 0) +
Statistic_AddValue(PChar, "eng_KillShip", 0) +
Statistic_AddValue(PChar, "fra_KillShip", 0) +
Statistic_AddValue(PChar, "spa_KillShip", 0) +
Statistic_AddValue(PChar, "hol_KillShip", 0);
}
}
void IsabellaCheckBreachState()
{
int iTemp;
iTemp = Statistic_AddValue(PChar, "pir_KillFort", 0) +
Statistic_AddValue(PChar, "eng_KillFort", 0) +
Statistic_AddValue(PChar, "fra_KillFort", 0) +
Statistic_AddValue(PChar, "spa_KillFort", 0) +
Statistic_AddValue(PChar, "hol_KillFort", 0);
if (iTemp > sti(pchar.RomanticQuest.State.KillFort)) pchar.RomanticQuest.Cheking.KillFort = iTemp - sti(pchar.RomanticQuest.State.KillFort);
iTemp = Statistic_AddValue(PChar, "pir_TakeTown", 0) +
Statistic_AddValue(PChar, "eng_TakeTown", 0) +
Statistic_AddValue(PChar, "fra_TakeTown", 0) +
Statistic_AddValue(PChar, "spa_TakeTown", 0) +
Statistic_AddValue(PChar, "hol_TakeTown", 0);
if (iTemp > sti(pchar.RomanticQuest.State.TakeTown)) pchar.RomanticQuest.Cheking.TakeTown = iTemp - sti(pchar.RomanticQuest.State.TakeTown);
iTemp = Statistic_AddValue(PChar, "pir_GrabbingTown", 0) +
Statistic_AddValue(PChar, "eng_GrabbingTown", 0) +
Statistic_AddValue(PChar, "fra_GrabbingTown", 0) +
Statistic_AddValue(PChar, "spa_GrabbingTown", 0) +
Statistic_AddValue(PChar, "hol_GrabbingTown", 0);
if (iTemp > sti(pchar.RomanticQuest.State.GrabbingTown)) pchar.RomanticQuest.Cheking.GrabbingTown = iTemp - sti(pchar.RomanticQuest.State.GrabbingTown);
iTemp = Statistic_AddValue(PChar, "pir_AbordShip", 0) +
Statistic_AddValue(PChar, "eng_AbordShip", 0) +
Statistic_AddValue(PChar, "fra_AbordShip", 0) +
Statistic_AddValue(PChar, "spa_AbordShip", 0) +
Statistic_AddValue(PChar, "hol_AbordShip", 0);
if (iTemp > sti(pchar.RomanticQuest.State.AbordShip)) pchar.RomanticQuest.Cheking.AbordShip = iTemp - sti(pchar.RomanticQuest.State.AbordShip);
iTemp = Statistic_AddValue(PChar, "pir_KillShip", 0) +
Statistic_AddValue(PChar, "eng_KillShip", 0) +
Statistic_AddValue(PChar, "fra_KillShip", 0) +
Statistic_AddValue(PChar, "spa_KillShip", 0) +
Statistic_AddValue(PChar, "hol_KillShip", 0);
if (iTemp > sti(pchar.RomanticQuest.State.KillShip)) pchar.RomanticQuest.Cheking.KillShip = iTemp - sti(pchar.RomanticQuest.State.KillShip);
return;
}
void IsabellaNullBudget()
{
pchar.RomanticQuest.Budget = "0";
SaveCurrentQuestDateParam("RomanticQuest.Budget");
}
int IsabellaCheckBudgetMoney()
{
int Debt = GetQuestPastMonthParam("RomanticQuest.Budget")*MOD_SKILL_ENEMY_RATE*10000;
int CurMoney = sti(pchar.RomanticQuest.Budget);
return Debt - CurMoney;
}
void IsabellaAddMoneyBudget(int _money)
{
pchar.RomanticQuest.Budget = sti(pchar.RomanticQuest.Budget) + _money;
AddMoneyToCharacter(pchar, -_money);
}
