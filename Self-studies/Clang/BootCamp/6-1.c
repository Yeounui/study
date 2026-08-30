#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define HEIGHT 256
#define WIDTH  256

void loadImage(void);
void displayImage(const char str[]);
void addImage(unsigned int value);
void subImage(unsigned int value);
void mulImage(unsigned int value);
void divImage(unsigned int value);

unsigned char m_image[HEIGHT][WIDTH];
char fullname[200] = "./LENA256.RAW";

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    loadImage();
    addImage(100);
	addImage(100);
	mulImage(2);
	divImage(2);
    SDL_Quit();
    return 0;
}

void loadImage(void) {
    FILE *rfp = fopen(fullname, "rb");
    if (!rfp) {
        fprintf(stderr, "Failed to open %s\n", fullname);
        return;
    }
    fread(m_image, 1, HEIGHT * WIDTH, rfp);
    fclose(rfp);

    displayImage("Original_Image");
}

void displayImage(const char str[]) {
    /* ── 창 & 렌더러 생성 ── */
    SDL_Window *window = SDL_CreateWindow(
        str,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (!renderer) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return;
    }

    /* ── Grayscale 텍스처 생성 (SDL_PIXELFORMAT_RGB24 사용) ── */
    SDL_Texture *texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGB24,      // R=G=B=gray 로 채울 것
        SDL_TEXTUREACCESS_STREAMING,
        WIDTH, HEIGHT
    );
    if (!texture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateTexture Error: %s\n", SDL_GetError());
        return;
    }

    /* ── m_image(1ch) → RGB 버퍼(3ch) 변환 후 업로드 ── */
    unsigned char rgb[HEIGHT * WIDTH * 3];
    for (int i = 0; i < HEIGHT * WIDTH; i++) {
        rgb[i * 3 + 0] = m_image[i / WIDTH][i % WIDTH]; // R
        rgb[i * 3 + 1] = m_image[i / WIDTH][i % WIDTH]; // G
        rgb[i * 3 + 2] = m_image[i / WIDTH][i % WIDTH]; // B
    }
    SDL_UpdateTexture(texture, NULL, rgb, WIDTH * 3);

    /* ── .pgm 저장 (기존 동작 유지) ── */
    char savename[200];
    snprintf(savename, sizeof(savename), "%s.pgm", str);
    FILE *wfp = fopen(savename, "wb");
    if (wfp) {
        fprintf(wfp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
        fwrite(m_image, 1, HEIGHT * WIDTH, wfp);
        fclose(wfp);
    }

    /* ── 렌더링 루프: 창을 닫거나 키를 누를 때까지 표시 ── */
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_Event e;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)                    running = 0;
            if (e.type == SDL_KEYDOWN)                 running = 0;
        }
        SDL_Delay(16); // ~60fps
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
};

void addImage(unsigned int value) {
    for (int r = 0; r < HEIGHT; r++)
        for (int c = 0; c < WIDTH; c++) {
                int v = (int)m_image[r][c] + value;
                m_image[r][c] = (unsigned char)(v > 255 ? 255 : v < 0 ? 0 : v);
            }
    displayImage("Added_Image");
}

void subdImage(unsigned int value) {
    for (int r = 0; r < HEIGHT; r++)
        for (int c = 0; c < WIDTH; c++) {
                int v = (int)m_image[r][c] - value;
                m_image[r][c] = (unsigned char)(v > 255 ? 255 : v < 0 ? 0 : v);
            }
    displayImage("Added_Image");
}

void mulImage(unsigned int value) {
    for (int r = 0; r < HEIGHT; r++)
        for (int c = 0; c < WIDTH; c++) {
                int v = (int)m_image[r][c] * value;
                m_image[r][c] = (unsigned char)v;
            }
    displayImage("Multiplied_Image");
}

void divImage(unsigned int value) {
    if (value == 0) { fprintf(stderr, "divided by zero\n"); return; }
    for (int r = 0; r < HEIGHT; r++)
        for (int c = 0; c < WIDTH; c++) {
                int v = (int)m_image[r][c] / value;
                m_image[r][c] = (unsigned char)v;
            }
    displayImage("Divided_Image");
}