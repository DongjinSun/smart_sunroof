#include "mode.h"

while (1) {


    // ä����� //
    sensorBrightness = getbright();
    userBrightness = modifyuserbright();  //�������׿� ���� ����(�������� �Է�)

    if (brightModeSwitch) { // ��� ��尡 Ȱ��ȭ�Ǿ� ���� ��
        if (userBrightness >= sensorBrightness) {
            if (ismax()) {
                break; // ���� ����
            }
            else {
                if (motorState != open()) {
                    openmax(); // ���� ����
                    motorState = open();
                }
            }
        }
        else {
            if (ismin()) {
                break; // 
            }
            else {
                if (motorState != open()) {
                    closemin(); // ���� �ݱ�  close min �̻���
                    motorState = open();
                }
            }
        }
    }

    updateMotorState(); // ������ ���¸� �ֱ������� ������Ʈ
}
