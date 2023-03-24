#include <iostream>
#include <conio.h>


//      " //* " 을 붙인 부분이 수정및 추가내용


//* 
void Damage(
    const int& _Att,  // 때리는 쪽의 공격력
    int& _Hp // 맞는 쪽의 체력
)
{
    _Hp -= _Att;
}

//* 
void AnnounceDamaged(
    const char* const _AttName, // 때리는 족의 이름
    const char* const _DefName, // 맞는 쪽의 이름
    const int& _Att // 때리는 쪽의 공격력
)
{

    printf_s("%s가 공격을 시작합니다\n", _AttName);
    printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

void StatusRender(
    const char* const _Name, // 때리는 족의 이름
    const int& _Att,  // 때리는 쪽의 공격력
    const int& _Hp // 맞는 쪽의 체력
)
{
    printf_s("%s 의 스테이터스 ------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _Hp);
    printf_s("---------------------------\n");
}

//*
void ClearAndAllStatusRender(
    const int& P_Att, const int& P_Hp,
    const int& M_Att, const int& M_Hp
    )
{
        system("cls");
        StatusRender("Player", P_Att, P_Hp);
        StatusRender("Monster", M_Att, M_Hp);
}



int main()
{

    int PlayerHp = 100;
    int PlayerAtt = 10;

    int MonsterHp = 100;
    int MonsterAtt = 10;

    while (true)
    {
        
        
        ClearAndAllStatusRender(PlayerAtt, PlayerHp, MonsterAtt, MonsterHp);
        _getch();

        

        Damage( PlayerAtt, MonsterHp);
        ClearAndAllStatusRender(PlayerAtt, PlayerHp, MonsterAtt, MonsterHp);
        AnnounceDamaged("Player", "Monster", PlayerAtt);
         _getch();


         


        if (0 >= MonsterHp)
        {
            ClearAndAllStatusRender(PlayerAtt, PlayerHp, MonsterAtt, MonsterHp);
            printf_s("몬스터가 죽었습니다.");
            printf_s("플레이어의 승리입니다.");
            _getch();
            break;
        }

        Damage( MonsterAtt, PlayerHp);
        ClearAndAllStatusRender(PlayerAtt, PlayerHp, MonsterAtt, MonsterHp);
        AnnounceDamaged("Monster", "Player", MonsterAtt);
        _getch();


       


        if (0 >= PlayerHp)
        {
            ClearAndAllStatusRender(PlayerAtt, PlayerHp, MonsterAtt, MonsterHp);
            printf_s("플레이어가 죽었습니다.");
            printf_s("몬스터의 승리입니다.");
            _getch();
            break;
        }
    }
}
