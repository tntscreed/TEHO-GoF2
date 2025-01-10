void TraceQuestFiles(string sQuestName, string qname)
{
if (bQuestLogShow)
{
if(qname != "")
{
Log_Info("Quest completed : " + sQuestName + " param = " + qname);
trace("Quest completed : " + sQuestName + " param = " + qname + " " + GetQuestBookDataDigit());
}
else
{
Log_Info("Quest completed : " + sQuestName);
trace("Quest completed : " + sQuestName + " " + GetQuestBookDataDigit());
}
}
if (CheckAttribute(pchar, "quest." + qname + ".function"))
{
string sFunction = pchar.quest.(qname).function;
call sFunction(qname);
return;
}
}