// 지금은 예제함수가 짧지만, 함수가 지금보다 더 길어진다면,
// 함수를 한 파일 안에서 정의하면 코드의 가독성이 떨어짐.
// 파일 쪼개기와 헤더파일을 사용해야 함!
// 물론 보통은 이렇게 짧은 하나의 함수를 위해서 새로운 파일로 쪼개는 경우는 거의 없고,
// 주로 객체지향에서 클래스를 추출할 때 파일을 새로 쪼개서 만드는 경우가 많음
int add(int a, int b)
{
    return a + b;
}